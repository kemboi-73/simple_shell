#ifndef SHELL_H
#define SHELL_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_TOKENS 1024
#define MAX_TOKEN_LENGTH 1024
#define MAX_BUFFER 100
#define EXIT_CODE 1080

/*protoypes of cd_command.c*/
int cd(char *directory);
/*prototype of get_loc.c*/
char *get_location(char *command);
/*protoype of command_exemd.c*/
void exemdd(char **argv);
int stat(const char *pathname, struct stat *statbuf);

/*proto of getline.c*/
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
/*char *_getenv(const char *name);*/
void inter_mode(void);
/*pro comment.c*/
void handleComment(char *string);

/* new */
int execute_command(char **args);
void handlecomment(char *string);
/*pro of exxit.c*/
int exitbuilt(char **a);
void ffree(char **a, char *istr);
/*pro of exit*/
char *get_line(void);


int _strcmp(const char *s1, const char *s2);
int is_in_str(const char *str, char c);

/*hh*/
int builtin_exit(void);
int builtin_env(char **env);
int execute_exit(char **args);


char *rem_cmnt(char *in);
#endif

