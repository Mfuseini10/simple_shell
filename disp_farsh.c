#include "farsh.h"

/*
 *disp_farsh_prompt- displays the simple shell prom
 *@argus - Arguments
 *
 * Return - Always 0 on success
 */

void disp_farsh_prompt(void)
{
	printf("farsh $ ");
}

int main(void)
{
	char type_in[MAX_COMMAND_LENGTH];
	char *argus[2];

	while (1)
	{
		disp_farsh_prompt();
	if (fgets(type_in, sizeof(type_in), stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		else
		{
			perror("Error  type_in");
			exit(EXIT_FAILURE);
		}
	}
	type_in[strlen(type_in) - 1] = '\0';
	args[0] = strtok(type_in, " ";

	if (argus[0] == NULL)
	{
	continue;
	}
	pid_t pid = fork();

	if (pid == -1)
	{
	perror("Fork err");
	exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
	if (execvp(argus[0], argus) == -1)
	{
		perror("Exec err");
	exit(EXIT_FAILURE);
	}
	}
	else
	{
		int detail;

		if (waitpid(pid, &detail, 0) == -1)
		{
			perror("Wait err");
			exit(EXIT_FAILURE);
		}
	}
	}
	return (0);
}
