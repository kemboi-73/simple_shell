#include "shell.h"
/**
 * main - entry point to the program
 * @argc: Argument count
 * @argv: Array of arguments
 *Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{	char *prompt = "(Sshell)$ ";
	char *lineptr = NULL, *copy_lineptr = NULL;
	size_t n = 0;
	ssize_t checkread;
	char *delin = " \n";
	int sum_token = 0, i;
	char *token;
	char **cmd_args = NULL;
	(void)argv;
	(void)argc;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("%s", prompt);
		checkread = getline(&lineptr, &n, stdin);
		if (checkread == -1)
		{
			free(lineptr);
			return (0); }
		copy_lineptr = malloc(sizeof(char) * checkread);
		if (copy_lineptr == NULL)
		{ printf("Allocation error\n");
			free(lineptr);
			return (-1);
		}
		strcpy(copy_lineptr, lineptr), token = strtok(lineptr, delin);
		while (token != NULL)
		{sum_token++;
		token = strtok(NULL, delin); }
		sum_token++;
		cmd_args = malloc(sizeof(char *) * sum_token);
		if (cmd_args == NULL)
		{ printf("Allocation error\n");
			free(copy_lineptr);
			free(lineptr);
			return (-1);
			break; }
		token = strtok(copy_lineptr, delin);
		if (cmd_args != NULL)
			for (i = 0; token != NULL; i++)
			{ cmd_args[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (cmd_args[i] == NULL)
		{ printf("Allocation error\n");
		free(copy_lineptr);
		free(cmd_args[i]);
		free(lineptr);
		cmd_args = NULL;
		return (-1);
		} strcpy(cmd_args[i], token), token = strtok(NULL, delin);
	} cmd_args[i] = NULL;
		execmd(cmd_args);
		free(cmd_args);
		free(copy_lineptr); }
	free(lineptr);
	return (0);
}
