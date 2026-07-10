#include "shell.h"

/**
 * execute - executes a command
 * @line: command line entered by the user
 */
void execute(char *line)
{
	pid_t pid;
	char *args[32];
	char *cmd, *path;
	int i = 0;
	int count = 0;

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
		return;

	cmd = args[0];

	path = handle_path(cmd);

	if (path == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", cmd);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		free(path);
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		execve(path, args, environ);
		perror("./hsh");
		exit(127);
	}

	wait(NULL);

	free(path);
}
