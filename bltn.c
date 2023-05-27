#include "shell.h"
/**
 * _strlen - Calculate the length of a string
 *
 * @s: String
 * Return: Length of the string
 */
size_t _strlen(const char *s)
{
	size_t length = 0;

	while (s[length] != '\0')
	{
	length++;
}
return (length);
}
/**
 * builtin_exit - Exit the shell
 *
 * Return: 0 to exit the shell
 */
int builtin_exit(void)
{
	return (0);
}

/**
 * builtin_env - Print the environment variables
 *
 * @env: Environment variables
 *
 * Return: Always returns 1
 */
int builtin_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
	write(STDOUT_FILENO, env[i], _strlen(env[i]));
	write(STDOUT_FILENO, "\n", 1);
	}

	return (1);
}
