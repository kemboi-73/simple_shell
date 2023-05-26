#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: 0 (success)
 */
int main(int argc, char **argv)
{
	char *prompt = "(simple_shell)$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t checkread;
	const char *delin = " \n";
	int sum_token = 0, i;
	char *token;
	char **args = NULL;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		checkread = getline(&lineptr, &n, stdin);
		if (checkread == -1)
		{
			printf("Error\n");
			return (-1);
		}
		token = strtok(lineptr, delin);
		while (token != NULL)
		{
			sum_token++;
			token = strtok(NULL, delin);
		}
		args = malloc(sizeof(char *) * (sum_token + 1));
		if (args == NULL)
		{
			printf("Allocation error\n");
			return (-1);
		}
		token = strtok(lineptr, delin);
		for (i = 0; token != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * (strlen(token) + 1));
			if (args[i] == NULL)
			{
				printf("Allocation error\n");
				return (-1);
			} strcpy(args[i], token);
			token = strtok(NULL, delin);
		} args[i] = NULL;
		execmd(args);
		for (i = 0; i < sum_token; i++)
			free(args[i]);
		free(args);
		sum_token = 0;
	}
	free(lineptr);
	return (0);
}
