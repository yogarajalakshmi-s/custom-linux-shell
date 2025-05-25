#include "parser.h"
#include "executor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1024];

    while (1) {
        printf("mysh> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }

        Command* cmd = parse_command(input);
        if (!cmd) continue;

        if (cmd->args[0] != NULL) {
            execute_command(cmd);
        }

        free_command(cmd);
    }

    return 0;
}
