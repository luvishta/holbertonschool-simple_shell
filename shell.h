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

int main(void);
int main(int ac, char **av);
int main(int ac, char **av, char **env);

#endif
