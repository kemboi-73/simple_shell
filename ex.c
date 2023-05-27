#include "shell.h"
/**
 * execute_exit - Handle the "exit" command
 *
 * @args: Array of strings containing command and arguments
 *
 * Return: Status code of the command execution
 */
int execute_exit(char **args)
{
	if (args[1] != NULL)
	{
		int status = _atoi(args[1]);

		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
