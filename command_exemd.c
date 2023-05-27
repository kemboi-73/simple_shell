#include "shell.h"

/**
 * exemdd - function to handle the command line
 * @argv: the argument itself
 */
void exemdd(char **argv)
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
