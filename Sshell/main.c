#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *full_command, *lineptr = NULL, *cp_command = NULL;
	size_t n = 0;
	ssize_t nchar_read;
	const char *delim = " \n";
	char *token;
	char **argv;
	int j;
	int num_token = 0;

	(void)argv;

	printf("$ ");

	
	nchar_read = getline(&lineptr, &n, stdin);
	
	cp_command = malloc(sizeof(char) * nchar_read);

	if (cp_command == NULL)
	{
		perror("tsh: memory allocation error");
		return(-1);
	}
	strcpy(cp_command, full_command);
	if (nchar_read == -1)
        {
		printf("Exiting shell....\n");
		return(-1);
        }
	else
	{
		token = strtok(lineptr, delim);
	}

	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
	num_token++;

	argv = malloc(sizeof(char *) * num_token);

	token = strtok(cp_command, delim);

	for (j = 0; token != NULL; j++)
	{
		argv[j] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[j], token);
		strcat(full_command, " ");

		token = strtok(NULL, delim);
	}
	argv[j] = NULL;

	
	free(lineptr);
	free(full_command);
	free(cp_command);
	
	return(0);
}
