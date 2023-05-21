#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char *full_command = NULL, *cp_command = NULL;
    size_t n = 0;
    ssize_t nchar_read; /* number of characters the user types */
    char *token;
    const char *delim = " \n";
    char **argv;
    int j = 0; 
    int num_tokens = 0;

    // strcpy(command_copy, full_command);
    printf("$ ");

    nchar_read = getline(&full_command, &n, stdin);

    cp_command = malloc(sizeof(char) * nchar_read);

    if (cp_command == NULL){
        perror("tsh: memory allocation error");
        return (-1);
    }

    strcpy(cp_command, full_command);

    if (nchar_read == -1){
        printf("Exiting shell....\n");
        return (-1);
    }
    else {

        token = strtok(full_command, delim);

        while (token != NULL){
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        argv = malloc(sizeof(char *) * num_tokens);

        token = strtok(copy_command, delim);

        for (i = 0; token != NULL; i++){
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* execute the commands with execve */


        free(argv);
        free(full_command);
        free(copy_command);
    }

    return (0);
}

