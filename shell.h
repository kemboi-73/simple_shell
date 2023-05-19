#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

/*shell.c prototypes*/
int stat(const char *pathname, struct stat *statbuf);
int _putchar(char c);
void execmd(char **argv);
char *get_location(char *command);


/*all prototypes of command_location.c*/
int isShellInteractive(info_t *info);
int isDelimiter(char c, char *delim);
int isAlphabetic(int c);
int convertStringToInt(char *s);

#endif

