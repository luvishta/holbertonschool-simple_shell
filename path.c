#include "shell.h"
/**
 * handle_path - searches PATH for a command
 * @command: command entered by the user
 *
 * Return: full path if found, otherwise NULL
 */
char *handle_path(char *command)
{
	char *path_env, *path_copy, *token, *full_path;
	struct stat st;
	size_t len;

	if (strchr(command, '/'))
	{
		if (stat(command, &st) == 0)
			return (strdup(command));
		return (NULL);
	}
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		len = strlen(token) + strlen(command) + 2;

		full_path = malloc(len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
