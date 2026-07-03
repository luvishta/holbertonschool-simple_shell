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

        if (input == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        execute(input);

        free(input);
    }

    return (0);
}
