#include "main.h"

int main(int arg_c, char **argv)
{
	char *full_command, *lineptr = NULL, *cp_command = NULL;
	size_t n = 0;
	ssize_t nchar_read;
	const char *delim = " \n";
	char *token;
	int j;
	int num_token = 0;

	(void)arg_c;
	printf("$ ");
	return(0);

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

		token = strtok(NULL, delim);
	}
	argv[j] = NULL;

	
	free(lineptr);
	free(full_command);
	free(cp_command);
	
	return(0);
}
