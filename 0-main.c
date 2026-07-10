#include "shell.h"
/**
 * main - entry point for simple shell
 * Return: The last execution status code
 */
int main(void)
{
	char *input;
	int last_status = 0;
    int execute_return = 0;

	while (1)
	{
		input = read_line();

		if (input == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		execute_return = execute(input);
		if (execute_return == -1)
		{
			free(input);
			break;
		}
		last_status = execute_return;
		free(input);
	}
	return (last_status);
}
