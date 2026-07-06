#include "shell.h"
/**
 * execute - runs a command using a child process
 * @line: full path of the command to execute
 */
void execute(char *line)
{
	pid_t pid;
	char *args[2];
	int i = 0;
	int len;

	while (line[i] == ' ' || line[i] == '\t')
		i++;

	args[0] = &line[i];
	args[1] = NULL;

	len = i;
	while (line[len] != '\0')
		len++;

	if (len > i)
	{
		len--;
		while (len >= i && (line[len] == ' ' || line[len] == '\t'))
		{
			line[len] = '\0';
			len--;
		}
	}
	if (args[0][0] == '\0')
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
