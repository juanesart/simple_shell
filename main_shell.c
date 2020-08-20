#include "holberton.h"
/**
 * main - Holberton Shell
 * @ac: counter of argumments to receive
 * @av: pointer to args to receive
 * Return: 0 on success.
 */

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	size_t MaxSize = 1024;
	pid_t child_pid; /*variable to fork*/
	int input = 0;
	char **savingtok = NULL, *string = NULL, *ext = "exit\n";
	char *val = "\n";

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#$ ", 3);
		input = getline(&string, &MaxSize, stdin);
		command_D(input, string);
		if (_strcmp(string, ext) == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(string, val) == 0)
			continue;
		child_pid = fork();
		if (fork_process(child_pid, string, savingtok) == -1)
		{
			write(2, string, strlen(string));
			write(1, "command not found\n", 18);
			_free(savingtok);
			exit(EXIT_FAILURE);
		}
	}
	free(string);
	return (0);
}
