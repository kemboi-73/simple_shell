#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point of the simple shell program
 * @argc: Argument count
 * @argv: Array of arguments
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
	char *prompt = "(Sshell)$ ";
	char *lineptr = NULL, *copy_lineptr = NULL;
	size_t n = 0;
	ssize_t checkread;
	const char *delin = " \n";
	int sum_token = 0, i;
	char *token;
	char **cmd_args = NULL;

	(void)argc;

	while (1)
	{
		printf("%s", prompt);

		checkread = getline(&lineptr, &n, stdin);
		if (checkread == -1)
		{
			printf("Error\n");
			return (-1);
		}

		copy_lineptr = malloc(sizeof(char) * checkread);
		if (copy_lineptr == NULL)
		{
			printf("Allocation error\n");
			return (-1);
		}
		strcpy(copy_lineptr, lineptr);

		token = strtok(lineptr, delin);
		while (token != NULL)
		{
			sum_token++;
			token = strtok(NULL, delin);
		}
		sum_token++;

		cmd_args = malloc(sizeof(char *) * sum_token);
		if (cmd_args == NULL)
		{
			printf("Allocation error\n");
			free(copy_lineptr);
			return (-1);
		}

		token = strtok(copy_lineptr, delin);
		for (i = 0; token != NULL; i++)
		{
			cmd_args[i] = malloc(sizeof(char) * (strlen(token) + 1));
			if (cmd_args[i] == NULL)
			{
				printf("Allocation error\n");
				free(copy_lineptr);
				free(cmd_args);
				return (-1);
			}
			strcpy(cmd_args[i], token);
			token = strtok(NULL, delin);
		}
		cmd_args[i] = NULL;

		execmd(cmd_args);

		/* Cleanup memory */
		free(cmd_args);
		free(copy_lineptr);
	}

	free(lineptr);/* frees the lineptr memory */
	return (0);
}
