#include "shell.h"
/**
 * freearg - function that frees the array of commands
 * @arg: array of pointers to character
 * Return: nothing
 */
void freearg(char **arg)
{
	int i;

	if (arg == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; arg[i] != NULL; i++)
		free(arg[i]);
	free(arg);
}
