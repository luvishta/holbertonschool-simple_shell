#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
char *read_line(void);
void execute(char *line);
char *handle_path(char *command);
#endif
