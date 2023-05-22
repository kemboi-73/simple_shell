#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * execmd - function to handle command line
 * @argv: argument to be parsed
 *
 * Return: 0
 */
void execmd(char **argv)
{
	char *command = NULL;
	char *actual_cmd = NULL;

	if (argv && argv[0])
	{
		command = argv[0];
		actual_cmd = get_location(command);

		if (actual_cmd == NULL)
		{
			printf("Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Execution failed");
			exit(EXIT_FAILURE);
		}
	}
}
