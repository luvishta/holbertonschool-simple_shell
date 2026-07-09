#include "shell.h"

/**
 * execute - runs a command with arguments using a child process
 * @line: command entered by the user
 */
void execute(char *line)
{
	pid_t pid;
	char *args[32], *path;
	int i = 0, arg_count = 0;

	while (line[i] && arg_count < 31)
	{
		while (line[i] == ' ' || line[i] == '\t')
			line[i++] = '\0';
		if (!line[i])
			break;
		args[arg_count++] = &line[i];
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			i++;
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
		return;

	path = handle_path(args[0]);
	if (!path)
	{
		perror("./hsh");
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(path, args, environ);
		perror("./hsh");
		exit(127);
	}

	wait(NULL);
	free(path);
}
