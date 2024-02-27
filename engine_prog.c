#include "functions_dec.h"
char *appellation;
/**
 * main - Display the prompt, manage End-of-File (EOF),
 * and read from the file stream.
 * @argc: Number of arguments (unnecessary)
 * @argv: Command's argument vector
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	char *str = NULL;
	size_t size_of_buffer = 0;
	ssize_t file_string = 0;

	(void) argc;
	appellation = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		file_string = getline(&str, &size_of_buffer, stdin);
		if (file_string == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}

		if (str[file_string - 1]  == '\n')
			str[file_string - 1]  = '\0';
		if (*str == '\0')
			continue;
		if (shellreadcmd(str, file_string) == 2)
			break;
	}
	free(str);
	str = NULL;
	return (0);
}
/**
 * shellreadcmd - Manages the command line and performs tokenization.
 *@s: string
 *@file_stream: getline entry
 * Return: 0
 */
int shellreadcmd(char *s, size_t __attribute__((unused))file_stream)
{
	char *tkn = NULL;
	char *command_array[100];
	int cd;

	if (shellstrcmp(s, "exit") == 0)
		return (2);
	else if (shellstrcmp(s, "env") == 0)
		return (shellprintenv());
	else if (shellstr_n_cmp(s, "setenv", 6) == 0)
	{
		char *variable, *value;

		variable = strtok(s + 7, " ");
		value = strtok(NULL, " ");
		if (variable != NULL && value != NULL)
			return (shellsetenv(variable, value, 1));
		{
			fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			return (-1);
		}
	}
	else if (shellstr_n_cmp(s, "unsetenv", 8) == 0)
	{
		char *variable = strtok(s + 9, " ");

		if (variable != NULL)
			return (shellunsetenv(variable));
		{
			fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			return (-1);
		}
	}
	tkn = strtok(s, " "), cd = 0;
	while (tkn)
	{
		command_array[cd++] = tkn;
		tkn = strtok(NULL, " ");
	}
	command_array[cd] = NULL;
	return (shellvoke_call(command_array));
}
/**
 * cant_see_print - Displays if cmd is not found in PATH
 *
 * @cmd: This is a string provided by the stdin
 */
void cant_see_print(char *cmd)
{
	write(2, appellation, shellstrlen(appellation));
	write(2, ": 1: ", 5);
	write(2, cmd, shellstrlen(cmd));
	write(2, ": not found\n", 12);
}
/**
 * shellvoke_call - Invokes cmd, creates a child process, and
 * executes with execve.
 *
 * @cmd_arr: this is a string given by the stdin
 * Return: 0
 */
int shellvoke_call(char *cmd_arr[])
{
	char *execute_path_string = NULL;
	char *command = NULL;
	pid_t is_child;
	int stat;

	command = cmd_arr[0];
	execute_path_string = shellcreatepath(command);
	if (execute_path_string == NULL)
	{
		cant_see_print(command);
		return (3);
	}
	is_child = fork();
	if (is_child < 0)
	{
		perror("Error:");
		return (-1);
	}
	if (is_child > 0)
		wait(&stat);
	else if (is_child == 0)
	{
		(execve(execute_path_string, cmd_arr, environ));
		perror("Error:");
		exit(1);
	}
	free(execute_path_string);
	return (0);
}
