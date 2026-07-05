#include "shell.h"
/**
*read_line - reads what user types
*Return: pointer to the input string, or NULL on failure
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t len = 0;
	ssize_t n;
	int i = 0;

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);

	n = getline(&buf, &len, stdin);

	if (n == -1)
	{
		free(buf);
		return (NULL);
	}

	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == '\r')
		{
			buf[i] = '\0';
			break;
		}
		i++;
	}


	return (buf);
}
