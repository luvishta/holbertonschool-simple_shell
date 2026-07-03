#include "shell.h"

/**
  * main - entry point
  *
  * Return: Always 0
  */
int main(void)
{	
	char *input;

	while (1)
	{
		input = read_line();

		if (!input)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			break;
		}

		printf("%s\n", input);

		free(input);
	}
	return (0);
}
