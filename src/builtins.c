#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "builtins.h"

int is_builtin(char *cmd) {
    return strcmp(cmd, "cd") == 0 || strcmp(cmd, "exit") == 0;
}

void run_builtin(Command *cmd) {
    if (strcmp(cmd->args[0], "cd") == 0) {
        if (cmd->args[1] == NULL || chdir(cmd->args[1]) != 0) {
            perror("cd");
        }
    } else if (strcmp(cmd->args[0], "exit") == 0) {
        exit(0);
    }
}
