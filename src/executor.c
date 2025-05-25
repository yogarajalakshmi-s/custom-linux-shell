#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "executor.h"

void execute_command(Command* cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        if (cmd->input_redirect) {
            int fd = open(cmd->input_redirect, O_RDONLY);
            dup2(fd, STDIN_FILENO);
            close(fd);
        }
        if (cmd->output_redirect) {
            int fd = open(cmd->output_redirect, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        execvp(cmd->name, cmd->args);
        perror("execvp");
        exit(1);
    } else {
        if (!cmd->background) {
            waitpid(pid, NULL, 0);
        } else {
            printf("[Background] PID: %d\n", pid);
        }
    }
}

void execute_pipeline(Command** commands, int count) {
    int pipefd[2], prev_fd = -1;

    for (int i = 0; i < count; i++) {
        if (i < count - 1) pipe(pipefd);

        pid_t pid = fork();
        if (pid == 0) {
            if (i > 0) {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (i < count - 1) {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            }
            if (i < count - 1) close(pipefd[0]);

            if (commands[i]->input_redirect) {
                int fd = open(commands[i]->input_redirect, O_RDONLY);
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
            if (commands[i]->output_redirect) {
                int fd = open(commands[i]->output_redirect, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }

            execvp(commands[i]->name, commands[i]->args);
            perror("execvp");
            exit(1);
        } else {
            if (prev_fd != -1) close(prev_fd);
            if (i < count - 1) {
                close(pipefd[1]);
                prev_fd = pipefd[0];
            }
        }
    }

    for (int i = 0; i < count; i++) {
        wait(NULL);
    }
}
