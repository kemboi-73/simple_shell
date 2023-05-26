#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * get_location - gets the path to the command passed as argument
 * @cmd: command whose location is required
 *
 * Return: command path if found, otherwise NULL
 */
char *get_location(char *cmd)
{
	char *path = getenv("PATH");
	char *copy_path = NULL;
	char *path_tkn = NULL;
	char *file_path = NULL;
	int cmd_len, dir_len;
	struct stat buffer;

	if (path == NULL)
		return (NULL);
	copy_path = strdup(path);
	if (copy_path == NULL)
		return (NULL);
	cmd_len = strlen(cmd);
	path_tkn = strtok(copy_path, ":");
	while (path_tkn != NULL)
	{
		dir_len = strlen(path_tkn);
		file_path = malloc(cmd_len + dir_len + 2);
		if (file_path == NULL)
		{
			free(copy_path);
			return (NULL);
		}
		strcpy(file_path, path_tkn);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{
			free(copy_path);
			return (file_path);
		}
		else
		{
			free(file_path);
			path_tkn = strtok(NULL, ":"); }
	} free(copy_path);
	if (stat(cmd, &buffer) == 0)
	return (cmd);
	return (NULL);
}
