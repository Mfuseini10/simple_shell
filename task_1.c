#include "farsh.h"
/**
 *handle_child_execution - executes the pid
 *@cmd: command to be tyed in
 *
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
/**
 * main - the entery point
 *
 *Return: always (0) on success
 */
int main(void)
{char input[MAX_INPUT_LENGTH];
	pid_t child_pid = fork();

	while (true)
	{
		ssize_t read_len = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);
		/*** Displays the shell prompt **/
	write(STDOUT_FILENO, "farsh> ", 7);
	if (read_len == -1)
	{
		perror("Error (input)");
		continue;
	}
	else if (read_len == 0)
	{
		break;/** End the shell (Ctrl+D) **/}
	if (input[read_len - 1] == '\n')/* excluding the newline character **/
	{
		input[read_len - 1] = '\0';
	}
	if (child_pid == -1)
	{
		perror("Fork failed");
		continue;
	}
	else if (child_pid == 0)
	{handle_child_execution(input);/** Child process **/
	}
	else
	{int detail;/** Parent process executes after child process**/

	if (waitpid(child_pid, &detail, 0) == -1)
	{perror("Error: no such file/directory exit");
	}
	}
	}
	printf("EXIT...NEXT TIME!\n");
	return (0);
}
