#include "functions_dec.h"

/**
 * shellcreatepath -this function accepts string PATH and divides it to tokens,
 * afterwards, concats with "/" & command
 *@command: solves the issue of command given from the getline
 *
 * Return: new_path for use in command_read
 */
char *shellcreatepath(char *command)
{
	char *path = shellstrdup(shellgetenv("PATH"));
	int cd = 0, st = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = command;
	char *current_address = NULL;
	struct stat buf;

	current_address = malloc(sizeof(char) * 100);
	if (shellgetenv("PATH")[0] == ':')
		if (stat(command, &buf) == 0)
			return (shellstrdup(command));
	while (path_tokens != NULL)
	{
		path_array[cd++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[cd] = NULL;
	for (st = 0; path_array[st]; st++)
	{
		shellstrcpy(current_address, path_array[st]);
		shellstrcat(current_address, "/");
		shellstrcat(current_address, s2);
		shellstrcat(current_address, "\0");

		if (stat(current_address, &buf) == 0)
		{
			free(path);
			return (current_address);
		}
		else
			current_address[0] = 0;
	}
	free(path);
	free(current_address);

/* Here to ensure PATH is checked and command is locally present */
	if (stat(command, &buf) == 0)
		return (shellstrdup(command));
	return (NULL);
}
/**
 * shellsetenv -Initialize a new environment variable or modify an existing one
 * @variable: Name of the environment variable
 * @value: Value to set for the environment variable
 * @overwrite: If set to 1, overwrite the existing value; if 0,
 * do nothing if the variable exists.
 *
 * Return: 0 on success and -1 on failure
 */
int shellsetenv(char *variable, char *value, int overwrite)
{
	char *current_variable;
	char *previous_value;

	if (variable == NULL || value == NULL)
	{
		fprintf(stderr, "setenv: Invalid arguments\n");
		return (-1);
	}

	previous_value = shellgetenv(variable);

	if (previous_value != NULL && overwrite == 0)
	{
		fprintf(stderr, "setenv: Variable '%s' already exists\n", variable);
		return (-1);
	}

	current_variable = malloc(shellstrlen(variable) + shellstrlen(value) + 2);

	if (current_variable == NULL)
	{
		perror("setenv");
		return (-1);
	}

	/* Combines the variable name, '=', and value*/
	shellstrcpy(current_variable, variable);
	shellstrcat(current_variable, "=");
	shellstrcat(current_variable, value);

	/* Set the new environment var*/
	if (putenv(current_variable) != 0)
	{
		perror("setenv");
		free(current_variable);
		return (-1);
	}
	return (0);
}

/**
 * shellunsetenv - Delete an environment variable.
 * @variable: The identifier for the environment variable to be deleted.
 *
 * Return: 0 on success and -1 on failure
 */
int shellunsetenv(char *variable)
{
	if (variable == NULL)
	{
		fprintf(stderr, "unsetenv: Invalid argument\n");
		return (-1);
	}
	/* Utilize unsetenv to delete the specified environment variable. */
	if (unsetenv(variable) != 0)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
