#include "shell.h"
/**
 * execmd - function to handle command line
 * @argv: argument to be parsed
 *
 * Return: void
 */
void execmd(char **argv)
{
	char *command = NULL;
	char *actual_cmd = NULL;

	if (argv && argv[0])
	{
		command = argv[0];
		actual_cmd = get_location(command);
		if (actual_cmd == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			exit(EXIT_FAILURE);
		}
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execve(actual_cmd, argv, NULL) == -1)
			{
				perror("Execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid failed");
				exit(EXIT_FAILURE);
			}
			if (WIFEXITED(status))
			{
				int exit_status = WEXITSTATUS(status);
			}
		}
	}
}
