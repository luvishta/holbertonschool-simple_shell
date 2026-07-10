#include "shell.h"

/**
 * _get_env - Gets the value of an environment variable.
 *
 * @var: Name of the variable to find.
 *
 * Return: A copy of the variable value, or NULL if not found.
 */
char *_get_env(const char *var)
{
	char *tmp;
	char *key;
	char *value;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = my_strdup(environ[i]);

		if (tmp == NULL)
			return (NULL);

		key = strtok(tmp, "=");

		if (key && strcmp(key, var) == 0)
		{
			value = strtok(NULL, "");

			if (value)
			{
				value = my_strdup(value);
				free(tmp);
				return (value);
			}

			free(tmp);
			return (my_strdup(""));
		}

		free(tmp);
	}

	return (NULL);
}
