#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 64

typedef struct {
    char *args[MAX_ARGS];
    int background;
} Command;


Command* parse_command(char *input);
void free_command(Command *cmd);

#endif // PARSER_H
