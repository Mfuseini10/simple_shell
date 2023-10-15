#ifndef _FARSH_H_
#define _FARSH_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

#define FAR_COMMAND_BUFFER_SIZE 64
#define FAR_COMMAND_DELIMITER " \t\r\n\a"
#define MAX_INPUT_LENGTH 64


void far_shell_run(void);
char *far_read_input(void);
char **far_tokenize_input(char *input);
int far_execute_command(char **args);

pid_t getpid(void);
pid_t getppid(void);
void handle_child_execution(const char *cmd);



#endif
