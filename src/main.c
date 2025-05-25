#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

int main() {
    char input[1024];
    while (1) {
        printf("mysh> ");
        if (!fgets(input, sizeof(input), stdin)) break;

        if (strncmp(input, "exit", 4) == 0) break;

        int count;
        Command** cmds = parse_pipeline(input, &count);
        if (count == 1) {
            execute_command(cmds[0]);
        } else {
            execute_pipeline(cmds, count);
        }
        free_commands(cmds, count);
    }
    return 0;
}
