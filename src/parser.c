#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"

Command** parse_pipeline(char* input, int* count) {
    char* segments[MAX_ARGS];
    int seg_count = 0;
    char* token = strtok(input, "|");
    while (token && seg_count < MAX_ARGS) {
        segments[seg_count++] = token;
        token = strtok(NULL, "|");
    }

    Command** commands = malloc(sizeof(Command*) * seg_count);
    for (int i = 0; i < seg_count; i++) {
        commands[i] = malloc(sizeof(Command));
        commands[i]->input_redirect = NULL;
        commands[i]->output_redirect = NULL;
        commands[i]->background = 0;

        char* arg = strtok(segments[i], " \t\n");
        int argc = 0;
        while (arg && argc < MAX_ARGS - 1) {
            if (strcmp(arg, "<") == 0) {
                arg = strtok(NULL, " \t\n");
                commands[i]->input_redirect = strdup(arg);
            } else if (strcmp(arg, ">") == 0) {
                arg = strtok(NULL, " \t\n");
                commands[i]->output_redirect = strdup(arg);
            } else if (strcmp(arg, "&") == 0) {
                commands[i]->background = 1;
            } else {
                commands[i]->args[argc++] = strdup(arg);
            }
            arg = strtok(NULL, " \t\n");
        }
        commands[i]->args[argc] = NULL;
        commands[i]->name = commands[i]->args[0];
    }
    *count = seg_count;
    return commands;
}

void free_commands(Command** commands, int count) {
    for (int i = 0; i < count; i++) {
        free(commands[i]);
    }
    free(commands);
}
