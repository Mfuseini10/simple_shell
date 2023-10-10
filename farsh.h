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

int atoi(const char *str);
int main(int argc, char *argv[], char **env);
pid_t getpid(void);
pid_t getppid(void);
ssize_t getline(char **lineptr, size_t *n, FILE *stdin);
char** split_string(const char *str, const char *delim, int *argc);
int check_file_status(const char *filename, struct stat *statbuf);
void disp_farsh_prompt();

char *my_strcpy(const char *src);

void str_cmb(char **buffer, char *str1, char *str2);

char **get_path(void);

#endif
