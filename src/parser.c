#include "parser.h"
#include <stdlib.h>
#include <string.h>

Command* parse_command(char* input) {
    Command* cmd = malloc(sizeof(Command));
    if (!cmd) return NULL;

    cmd->background = 0;
    int i = 0;

    char* token = strtok(input, " \t\n");
    while (token != NULL && i < MAX_ARGS - 1) {
        if (strcmp(token, "&") == 0) {
            cmd->background = 1;
        } else {
            cmd->args[i++] = strdup(token);
        }
        token = strtok(NULL, " \t\n");
    }

    cmd->args[i] = NULL;
    return cmd;
}

void free_command(Command* cmd) {
    if (!cmd) return;
    for (int i = 0; cmd->args[i] != NULL; i++) {
        free(cmd->args[i]);
    }
    free(cmd);
}
