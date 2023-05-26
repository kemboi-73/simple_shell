#include "shell.h"
/**
 * main - Entry point of the shell program
 * @argc: Argument count
 * @argv: Array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *prompt = "(simple_shell)$ ", *lineptr = NULL, *token, **args = NULL;
	size_t n = 0;
	ssize_t checkread;
	const char *delin = " \n";
	int sum_token = 0, i;
	(void)argc, (void)argv;
	while (1)
	{
		perror(prompt);
		checkread = getline(&lineptr, &n, stdin);
		if (checkread == -1)
		{
			perror("Error\n");
			return (-1); }
		token = strtok(lineptr, delin);
		while (token != NULL)
		{
			sum_token++;
			token = strtok(NULL, delin); }
		args = malloc(sizeof(char *) * (sum_token + 1));
		if (args == NULL)
		{
			perror("Allocation error\n");
			return (-1); }
		token = strtok(lineptr, delin);
		for (i = 0; token != NULL; i++)
		{
			args[i] = malloc(sizeof(char) * (strlen(token) + 1));
			if (args[i] == NULL)
			{
				perror("Allocation error\n");
				return (-1);
	} strcpy(args[i], token);
			token = strtok(NULL, delin);
		} args[i] = NULL;
		execmd(args);
		for (i = 0; i < sum_token; i++)
			free(args[i]);
		free(args), sum_token = 0; }
	free(lineptr);
	return (0); }
