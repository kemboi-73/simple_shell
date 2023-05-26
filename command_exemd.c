#include "shell.h"

/**
 * execmd - handles the command line
 * @argv: the argument itself
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;

	if (argv)
	{
	command = argv[0];
		actual_cmd = get_location(command);

if (execve(actual_cmd, argv, NULL) == -1)
	{
perror("Oops! An error occurred.\n");
	}
	}
}

