#include "shell.h"
/**
 * main - entry point for simple shell
 * Return: The last execution status code
 */
int main(void)
{
	char *input;
	int last_status = 0;

	while (1)
	{
		input = read_line();
		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		last_status = execute(input);
		free(input);
	}
	return (last_status);
}
