#include "farsh.h"
/**
 *far_shell_run -a function that repeat prompt for user for command
 *@far_input -
 *
 *
 *
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
		far_exit_code = far_execute_command(far_parsed_args);
		free(far_input_line);
		free(far_parsed_args);
	} while (far_exit_code);
}
/**
   *far_read_input - a pointer to a memory string to store
   *Return: input
   */
char *far_read_input(void)
{
	char *far_input = NULL;
	size_t far_buffer_size = 0;
	ssize_t read_len = getline(&far_input, &far_buffer_size, stdin);

	if (read_len == -1)
	{
		if (feof(stdin))
		{
			_exit(EXIT_SUCCESS);
		}
		else
		{
			perror("farsh: getline\n");
			_exit(EXIT_FAILURE);
		}
	}
	return (far_input);
}
/**
 * far_tokenize_input -tokenize, handle memory alloc and checks for errors
 * @input: a pointer to stdin
 * Return: input
 */
char **far_tokenize_input(char *input)
{
	int far_buffer_size = FAR_COMMAND_BUFFER_SIZE;
	int far_position = 0;
	char *far_token, **far_tokens_copy;
	char **far_command_tokens = (char **)
		malloc(far_buffer_size * sizeof(char *));
	if (!far_command_tokens)
	{
		fprintf(stderr, "farsh: allocation error\n");
		_exit(EXIT_FAILURE);
	}
	far_token = strtok(input, FAR_COMMAND_DELIMITER);
	while (far_token != NULL)
	{
		far_command_tokens[far_position] = far_token;
		far_position++;
		if (far_position >= far_buffer_size)
		{
			far_buffer_size += FAR_COMMAND_BUFFER_SIZE;
			far_tokens_copy = far_command_tokens;
			far_command_tokens = (char **)realloc(far_command_tokens,
					far_buffer_size * sizeof(char *));
			if (!far_command_tokens)
			{
				free(far_tokens_copy);
				fprintf(stderr, "farsh: allocation error\n");
				_exit(EXIT_FAILURE);
			}
		}
		far_token = strtok(NULL, FAR_COMMAND_DELIMITER);
	}
	far_command_tokens[far_position] = NULL;
	return (far_command_tokens);
}
/**
 * far_execute_command - executing the commands
 *@args: nunber of arguments
 *
 * return: always (1) on success
 */
int far_execute_command(char **args)
{
	int q = 1;

	if (args[0] == NULL)
	{
		return (1);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		printf("Exiting the shell.\n");
		return (0);
	}
	else if (strcmp(args[0], "echo") == 0)
	{
		for (q = 1; args[q] != NULL; q++)
		{
			printf("%s ", args[q]);
		}
		printf("\n");
	}
	else
	{
		pid_t pid = fork();

		if (pid == 0)
		{execvp(args[0], args);
			perror("farsh");
			_exit(EXIT_FAILURE); /* If exec fails*/
		}
		else if (pid < 0)
		{
			perror("farsh");
		}
		else
		{
			int status;/* Parent process*/

			waitpid(pid, &status, 0);
		}
	}
	return (1);
}
