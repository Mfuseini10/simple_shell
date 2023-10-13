#ifndef _FARSH_H_
#define _FARSH_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256
#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 64


pid_t getpid(void);
pid_t getppid(void);
void handle_child_execution(const char *cmd);



#endif
