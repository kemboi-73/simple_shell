#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - main function of code
 * @argc: argument parsed
 * @argv: arguments
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt = "(Sshell)$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t checkread;
	const char *delim = " \n";
	char *copy_lineptr = strdup(lineptr);
	int sum_token = 0;
	char *token = strtok(lineptr, delim);
	char **arguments = malloc(sizeof(char *) * (sum_token + 1));
	int i = 0;

	
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);

		checkread = getline(&lineptr, &n, stdin);
		
		if (checkread == -1)
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}

		if (copy_lineptr == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}


		while (token != NULL)
		{
			sum_token++;
			token = strtok(NULL, delim);
		}

		if (arguments == NULL)
		{
			perror("Allocation error");
			free(copy_lineptr);
			exit(EXIT_FAILURE);
		}

		token = strtok(copy_lineptr, delim);

		while (token != NULL)
		{
			arguments[i] = strdup(token);
			if (arguments[i] == NULL)
			{
				perror("Allocation error");
				free(copy_lineptr);
				free(arguments);
				exit(EXIT_FAILURE);
			}

			token = strtok(NULL, delim);
			i++;
		}
		arguments[i] = NULL;

		execmd(arguments);

		free(copy_lineptr);
		free(arguments);
	}
	free(lineptr);
	return (0);
}
