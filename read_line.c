#include "main.h"
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

	if (isatty(STDIN_FILENO))
		write(1, "$ ", 2);

	n = getline(&buf, &len, stdin);

	if (n == -1)
	{
		free(buf);
		return (NULL);
	}

	return (buf);
}
