#include "shell.h"

/**
 * execmd - function to handle the command line
 * @argv: argument
 */
void execmd(char **argv)
{
    char *command = NULL, *actual_cmd = NULL;

    if (argv)
    {
        command = argv[0];
        actual_cmd = get_location(command);

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        if (execve(actual_cmd, argv, NULL) == -1)
        {
            perror("Error:");
        }
    }
}

