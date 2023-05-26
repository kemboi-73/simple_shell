#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
/*protoypes of cd_command.c*/
int cd(char *directory);
/*prototype of get_loc.c*/
char *get_location(char *command);
/*protoype of command_exemd.c*/
void execmd(char **argv);
int stat(const char *pathname, struct stat *statbuf);

/*proto of builtn.c*/
int builtin_exit(void);
int builtin_env(char **env);
#endif
