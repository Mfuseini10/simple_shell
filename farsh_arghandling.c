#include "farsh.h"
/**
 * pid - process id
 * ppid - parent process id
 * return - 0 on success
 */

void execute_instruction(char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("farsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
	int details;

	waitpid(pid, &details, 0);
	}
	else
	{
		perror("farsh");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_LENGTH];

	while (1)
	{
		printf("farsh $ ");
		fgets(type_in, MAX_INPUT_LENGTH, stdin);
		type_in[strcspn(type_in, "\n")] = 0;

		char *token = strtok(input, " ");
		int arg_count = 0;

		while (token != NULL && arg_count < MAX_ARG_LENGTH - 1)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (arg_count > 0)
		{
			execute_command(args);
		}
	}
	return (0);
}
