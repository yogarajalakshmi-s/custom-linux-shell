#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "executor.h"
#include "builtins.h"

void execute_command(Command *cmd) {
    if (is_builtin(cmd->args[0])) {
        run_builtin(cmd);
        return;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(cmd->args[0], cmd->args);
        perror("mysh");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        if (!cmd->background) {
            waitpid(pid, NULL, 0);
        }
    }
}
