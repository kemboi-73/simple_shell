#include "shell.h"

/**
 * exemd - function to handle the command line
 * @argv: argument
*/
void exemd(char **argv)
{
	char *command = NULL, *actual_cmd = NULL;
	pid_t pid;

	if (strcmp(command, "exit") == 0)
			exit(0);
	if (argv)
{
	command = argv[0];
	actual_cmd = get_location(command);
		pid = fork();
		if (pid < 0)
		write(2, "fork", 4);
	else if (pid == 0)
{
if (execve(actual_cmd, argv, NULL) == -1)
{
	perror("Oops! An error occurred.\n");
	exit(1);
	}
exit(0);
	}
}
}
