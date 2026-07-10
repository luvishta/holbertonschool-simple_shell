#include "shell.h"
/**
 * execute - executes a command
 * @line: command line entered by the user
 * Return: The exit status of the command execution
 */
int execute(char *line)
{
    pid_t pid;
    char *args[32];
    char *cmd, *path;
    int i = 0, count = 0;
    int status = 0;

    while (line[i] && count < 31)
    {
        while (line[i] == ' ' || line[i] == '\t')
            line[i++] = '\0';

        if (line[i] == '\0')
            break;

        args[count++] = &line[i];

        while (line[i] && line[i] != ' ' && line[i] != '\t')
            i++;
    }
    args[count] = NULL;

    if (count == 0)
        return (0);

    cmd = args[0];

	if (strcmp(cmd, "exit") == 0)
    {
        return (-1);
    }
    path = handle_path(cmd);

    if (path == NULL)
    {
        fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
        return (127);
    }

    pid = fork();
    if (pid == -1)
    {
        free(path);
        perror("fork");
        return (1);
    }

    if (pid == 0)
    {
        if (execve(path, args, environ) == -1)
        {
            perror("./hsh");
            free(path);
            exit(127);
        }
    }
    wait(&status);
    free(path);
    return (status / 256 );
}
