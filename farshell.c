#include "farsh.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 *main - simple shell program that is able to run shell commands
 *
 *
 *Return - zero (0) on success
 *
 */
 extern int execle (const char *__path, const char *__arg, ...);
int main(int argc, char *argv[], char **env)
{
	size_t bafa_size;
	ssize_t bytes;
	char *bafa = NULL;
	char *pmpt = "$ ";
	pid_t wpid;
	bool fapipe = false;
	struct stat statbafa;
	int wstat;

	while (1 && !fapipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			fapipe = true;

		write(STDOUT_FILENO, pmpt, 2);

		bytes = getline(&bafa, &bafa_size, stdin);
		if (bytes == -1)
		{
			perror("Error (getline)");
			free(bafa);
			exit(EXIT_FAILURE);
		}


int execute_command(char **args)
{
	if (bafa[bytes -1] == '\n')
		bafa[bytes -1] = '\0';
	
	int what_do = built_ins(args);

	if (what_do == DO_EXECVE)
	{
		command_name = check_command(args);
		if (command_name == NULL)
			return (FALSE);

		pid = fork();
		if (pid == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			execve(command_name, args, environ);
			exit(EXIT_FAILURE);
		}
		wait(&status);
		free(command_name);
		fflush(stdin);
		if (status != 0)
		status = 2;
	}
}
int _execute(char *arguments, struct stat *stabaf, char **envp)
{
	int argc;
	char **argv;
	char *exe;

	argv = split_string(arguments, " ", &argc);

	if (!check_file_status(argv[0], &statbafa))
	{
		perror("Error (file stat)");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);

	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

bool check_file_stat(char *pathname, struct stat *statbafa)
{
	int stat_return;

	stat_return = stat(pathname, statbafa);

	if (stat_return == 0)
		return (true);

	return (false);
}

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}


}
}
