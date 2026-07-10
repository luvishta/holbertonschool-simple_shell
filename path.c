#include "shell.h"

/**
 * handle_path - Finds the full path of a command.
 * @command: Command entered by the user.
 *
 * Return: Full path or NULL.
 */
char *handle_path(char *command)
{
	char *env, *path, *cmd;
	int len;

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (my_strdup(command));

		return (NULL);
	}

	env = _get_env("PATH");
	if (env == NULL)
		return (NULL);

	if (env[0] == '\0')
	{
		free(env);
		return (NULL);
	}

	path = strtok(env, ":");

	while (path != NULL)
	{
		len = strlen(path) + strlen(command) + 2;

		cmd = malloc(sizeof(char) * len);
		if (cmd == NULL)
		{
			free(env);
			return (NULL);
		}

		snprintf(cmd, len, "%s/%s", path, command);

		if (access(cmd, X_OK) == 0)
		{
			free(env);
			return (cmd);
		}

		free(cmd);
		path = strtok(NULL, ":");
	}

	free(env);

	return (NULL);
}
