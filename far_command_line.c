#include "farsh.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * far_shell_run - A function that repeats the prompt for the user to enter a command.
 */
void far_shell_run(void)
{
    char *far_input_line;
    char **far_parsed_args;
    int far_exit_code;

    do {
        printf("farsh>> ");
        far_input_line = far_read_input();
        far_parsed_args = far_tokenize_input(far_input_line);

        if (far_parsed_args) {
            far_exit_code = far_execute_command(far_parsed_args);
            free(far_input_line);
            free(far_parsed_args);
        } else {
            free(far_input_line);
            far_exit_code = 1; /* Handle the error condition*/
        }

    } while (far_exit_code);
}

/**
 * far_read_input - A function to read input from the user.
 * Returns the input string.
 */
char *far_read_input(void)
{
    char *far_input = NULL;
    size_t far_buffer_size = 0;

    if (getline(&far_input, &far_buffer_size, stdin) == -1) {
        if (feof(stdin)) {
            _exit(EXIT_SUCCESS);
        } else {
            perror("farsh: getline");
            _exit(EXIT_FAILURE);
        }
    }

    return far_input;
}

/**
 * far_tokenize_input - Tokenizes the input string and returns an array of tokens.
 * Returns NULL on failure.
 */
char **far_tokenize_input(char *input)
{
    char *token;
    int far_buffer_size = FAR_COMMAND_BUFFER_SIZE;
    int far_position = 0;
    char **far_command_tokens = (char **)malloc(far_buffer_size * sizeof(char *));

    if (!far_command_tokens) {
        fprintf(stderr, "farsh: allocation error\n");
        _exit(EXIT_FAILURE);
    }

    token = strtok(input, " \n"); /** Tokenize based on space and newline*/

    while (token != NULL) {
        far_command_tokens[far_position] = strdup(token);

        if (!far_command_tokens[far_position]) {
            perror("farsh: strdup");
            _exit(EXIT_FAILURE);
        }

        far_position++;

        if (far_position >= far_buffer_size) {
            far_buffer_size += FAR_COMMAND_BUFFER_SIZE;
            far_command_tokens = (char **)realloc(far_command_tokens, far_buffer_size * sizeof(char *));
            if (!far_command_tokens) {
                perror("farsh: realloc");
                _exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, " \n");
    }

    far_command_tokens[far_position] = NULL;
    return far_command_tokens;
}

/**
 * far_execute_command - A function that executes the given command.
 * Returns 0 if the shell should exit, 1 otherwise.
 */
int far_execute_command(char **args)
{
	int i;

    if (args[0] == NULL) {
        return 1;
    } else if (strcmp(args[0], "exit") == 0) {
        printf("Exiting the shell.\n");
        return 0;
    } else if (strcmp(args[0], "echo") == 0) {
        for (i = 1; args[i] != NULL; i++) {
            printf("%s ", args[i]);
        }
        printf("\n");
    } else {
        pid_t pid = fork();

        if (pid == 0) {
            execvp(args[0], args);
            perror("farsh");
            _exit(EXIT_FAILURE); /** If exec fails**/
        } else if (pid < 0) {
            perror("farsh");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 1;
}
