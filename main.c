#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - main function
 * @a: argument counts
 * @argv: arguments
 *
 * Return: 0(success)
 */
int main(int a, char **argv)
{
    char *prompt = "(simple_shell)$ ";
    char *lineptr = NULL, *copy_lineptr = NULL;
    size_t n = 0;
    ssize_t checkread;
    const char *delin = " \n";
    int sum_token = 0, i, j;
    char *token;

    (void)a;

    while (1) {
        printf("%s", prompt);
        checkread = getline(&lineptr, &n, stdin);
        if (checkread == -1) {
            printf("Error\n");
            free(lineptr);
            return (-1);
        }

        /* Allocate memory for copy_lineptr with space for null terminator */
        copy_lineptr = malloc(sizeof(char) * (checkread + 1));
        if (copy_lineptr == NULL) {
            printf("Allocation error\n");
            free(lineptr);
            return (-1);
        }
        strcpy(copy_lineptr, lineptr);

        /* Count the number of tokens */
        token = strtok(copy_lineptr, delin);
        while (token != NULL) {
            sum_token++;
            token = strtok(NULL, delin);
        }
        sum_token++;

        /* Allocate memory for argv */
        argv = malloc(sizeof(char *) * sum_token);
        if (argv == NULL) {
            printf("Allocation error\n");
            free(lineptr);
            free(copy_lineptr);
            return (-1);
        }

        /* Tokenize the original lineptr and copy tokens to argv */
        token = strtok(lineptr, delin);
        for (i = 0; token != NULL; i++) {
            /* Allocate memory for each token with space for null terminator */
            argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
            if (argv[i] == NULL) {
                printf("Allocation error\n");
                free(lineptr);
                free(copy_lineptr);

                /* Free previously allocated argv elements */
                for (j = 0; j < i; j++) {
                    free(argv[j]);
                }
                free(argv);
                return (-1);
            }
            strcpy(argv[i], token);
            token = strtok(NULL, delin);
        }
        argv[i] = NULL;

        execmd(argv);

        /* Free allocated memory for each argv element */
        for (j = 0; argv[j] != NULL; j++) {
            free(argv[j]);
        }
        free(argv);
    }

    free(lineptr);
    free(copy_lineptr);

    return (0);
}

