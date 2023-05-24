#include "shell.h"
char *buf = NULL;

/**
 * handl_ctrlc - handls the ctrl c signal
 * @signal: the signal
 */

void handl_ctrlc(int signal)
{
    (void)signal;

    free(buf);
    exit(EXIT_SUCCESS);
}
void  handle_signale()
{
    if (signal(SIGINT, handl_ctrlc) == SIG_ERR)
        {
            /* If there is an error setting the signal handler*/
            const char* error_message = "An error occurred while setting a signal handler.\n";
            size_t message_length = strlen(error_message);
            ssize_t bytes_written = write(STDERR_FILENO, error_message, message_length);
                if (bytes_written < 0)
                {
                    perror("write");
                }
        exit(EXIT_FAILURE);
    }
}
