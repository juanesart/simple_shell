#include "holberton.h"
/**
 * fork_process - loop and validate the main process
 * @child_pid: id of child generated
 * @string: buffer of line writed
 * @savingtok: pointer to array to tokenize lines
 * Return: int
 */
int fork_process(pid_t child_pid, char *string, char **savingtok)
{
	if (child_pid == -1)
	{
		perror("child: error");
		return (1);
	}
	if (child_pid == 0)
	{
		savingtok = tokens(string);
		if (_path(savingtok) == -1)
			return (-1);
	}
	return (0);
}
/**
 * command_D - function that validate ctrl+d key
 * @ret: return getline
 * @string: buffer of line writed
 * Return: exit status
 */
int command_D(int ret, char *string)
{
	if (ret < 0)
	{
		if (isatty(0) == 1)
			write(1, "\n", 1);
		free(string);
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}
/**
 * _free - Write a function that returns a pointer to a 2 dimensional
 * @string: double pointer
 * No Return
 */
void _free(char **string)
{
	size_t i = 0;

	if (string == NULL)
		return;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}
