#include "farsh.h"
/**
 * main- the main entery
 *@cmd - command to be tyed in
 *@handle_child_execution - executes the child pid
 *Return - Always 0
 */
void handle_child_execution(const char *cmd)
{
	if (execlp(cmd, cmd, NULL) == -1)
	{
	perror("Command not found");
	_exit(EXIT_FAILURE);
	}
}

int main(void)
{char input[MAX_INPUT_LENGTH];

	while (true)
	{ssize_t read_len = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);
		/*** Displays the shell prompt **/
	write(STDOUT_FILENO, "simple_shell> ", 14);
	if (read_len == -1)
	{perror("Error (input)");
		continue;
	}
	else if (read_len == 0)
	{break;/** End the shell (Ctrl+D) **/}
	if (input[read_len - 1] == '\n')/* excluding the newline character **/
	{input[read_len - 1] = '\0';
	}
	pid_t child_pid = fork();/** Fork a child process **/

	if (child_pid == -1)
	{perror("Fork failed");
		continue;
	}
	else if (child_pid == 0)
	{handle_child_execution(input);/** Child process **/
	}
	else
	{int detail;/** Parent process executes after child process**/

	if (waitpid(child_pid, &detail, 0) == -1)
	{perror("Error waiting for child pID");
	}
	else
	{
		if (WIFEXITED(detail))
		{printf("Child pID exited %d\n", WEXITSTATUS(detail));
		}
		else
			perror("Child pID aborted");
	}
	}
	printf("EXIT...NEXT TIME!\n");
	return (0);
}
