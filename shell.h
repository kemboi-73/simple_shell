#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

int stat(const char *pathname, struct stat *statbuf);
void execmd(char **argv);
char *get_location(char *command);

#endif

