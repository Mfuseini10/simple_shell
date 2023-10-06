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

size_t my_strlen(const char *str);

char *my_strcpy(const char *src);

void str_cmb(char **buffer, char *str1, char *str2);

char **get_path(void);

#endif
