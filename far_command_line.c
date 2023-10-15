#include "farsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define FAR_COMMAND_BUFFER_SIZE 64
#define FAR_COMMAND_DELIMITER " \t\r\n\a"

void far_shell_run(void);
char *far_read_input(void);
char **far_tokenize_input(char *input);
int far_execute_command(char **args);


void far_shell_run(void) {
    char *far_input_line;
    char **far_parsed_args;
    int far_exit_code;

    do {
        printf("my_custom_shell>> ");
        far_input_line = far_read_input();
        far_parsed_args = far_tokenize_input(far_input_line);
        far_exit_code = far_execute_command(far_parsed_args);

        free(far_input_line);
        free(far_parsed_args);
    } while (far_exit_code);
}

char *far_read_input(void) {
    char *far_input = NULL;
    size_t far_buffer_size = 0;

    ssize_t read_len = getline(&far_input, &far_buffer_size, stdin);

    if (read_len == -1) {
        if (feof(stdin)) {
            _exit(EXIT_SUCCESS);
        } else {
            perror("my_custom_shell: getline\n");
            _exit(EXIT_FAILURE);
        }
    }

    return far_input;
}

char **far_tokenize_input(char *input) {
    int far_buffer_size = FAR_COMMAND_BUFFER_SIZE;
    int far_position = 0;
    char **far_command_tokens = (char **)malloc(far_buffer_size * sizeof(char *));
    char *far_token, **far_tokens_copy;

    if (!far_command_tokens) {
        fprintf(stderr, "my_custom_shell: allocation error\n");
        _exit(EXIT_FAILURE);
    }

    far_token = strtok(input, FAR_COMMAND_DELIMITER);

    while (far_token != NULL) {
        far_command_tokens[far_position] = far_token;
        far_position++;

        if (far_position >= far_buffer_size) {
            far_buffer_size += FAR_COMMAND_BUFFER_SIZE;
            far_tokens_copy = far_command_tokens;
            far_command_tokens = (char **)realloc(far_command_tokens, far_buffer_size * sizeof(char *));

            if (!far_command_tokens) {
                free(far_tokens_copy);
                fprintf(stderr, "my_custom_shell: allocation error\n");
                _exit(EXIT_FAILURE);
            }
        }

        far_token = strtok(NULL, FAR_COMMAND_DELIMITER);
    }

    far_command_tokens[far_position] = NULL;
    return far_command_tokens;
}

int far_execute_command(char **args) {
	int i = 1;
    if (args[0] == NULL) {
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
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
            /* Child process*/
            execvp(args[0], args);
            perror("my_custom_shell");
            _exit(EXIT_FAILURE); /* If exec fails*/
        } else if (pid < 0) {
            perror("my_custom_shell");
        } else {
            /* Parent process*/
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 1;
}

