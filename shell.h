#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
char *read_line(void);
char *_get_env(const char *var);
char *my_strdup(const char *str);
char *handle_path(char *command);
int execute(char *line);

#endif
