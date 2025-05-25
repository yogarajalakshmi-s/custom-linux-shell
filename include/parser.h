#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 64

typedef struct Command {
    char* name;
    char* args[MAX_ARGS];
    char* input_redirect;
    char* output_redirect;
    int background;
} Command;

Command** parse_pipeline(char* input, int* count);
void free_commands(Command** commands, int count);

#endif
