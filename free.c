#include "shell.h"
/**
 * free_all - function that frees all allocated memory
 * that needed to be freed
 * @buffer: buffer where getline stock the commands
 * @p: pointer to character
 * @arg: arry of pointers to character
 * Return: nothing
 */
void free_all(char *buffer, char *p, char **arg)
{
	free(buffer);
	free(p);
	freearg(arg);
}
