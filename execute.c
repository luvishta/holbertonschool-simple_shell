#include "shell.h"

/**
 * execute - runs a command with arguments using a child process
 * @line: string containing the command and its arguments
 */
void execute(char *line)
{
	pid_t pid;
	char *args[32];
	int i = 0;
	int arg_count = 0;

	while (line[i] != '\0' && arg_count < 31)
	{
		while (line[i] == ' ' || line[i] == '\t')
		{
			line[i] = '\0';
			i++;
		}

		if (line[i] == '\0')
			break;

		args[arg_count] = &line[i];
		arg_count++;

		while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
			i++;
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
		return;
	pid = fork();
	if (pid == -1)
		return;
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("./hsh");
			exit(127);
		}
	}
	wait(NULL);
}
