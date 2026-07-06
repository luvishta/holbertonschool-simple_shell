#include "shell.h"

/**
 *execute - runs a command using a child process
 *@line: full path of the command to execute
 */
void execute(char *line)
{
    pid_t pid;
    char *args[2];

    args[0] = line;
    args[1] = NULL;

    pid = fork();
    if (pid == -1)
        return;

    if (pid == 0)
    {
        execve(args[0], args, environ);
        exit(0);
    }

    wait(NULL);
}
