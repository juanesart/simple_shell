#include "holberton.h"

int fork_process(pid_t child_pid, char *string, char **savingtok)
{
	if (child_pid == -1)
	{
		perror("child: error");
		return(1);
	}
	if (child_pid == 0)
	{
                savingtok = tokens(string);
                if (_path(savingtok) == -1)
                        return(-1);
		
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

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