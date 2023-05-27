#include "shell.h"

/**
 * exemd - function to handle the command line
 * @argv: argument
 */
void exemd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;

	if (argv)
	{
		command = argv[0];
		actual_cmd = get_location(command);

		if (execve(actual_cmd, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
