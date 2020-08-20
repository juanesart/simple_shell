#include "holberton.h"

int fork_process(pid_t child_pid, char *string, char **savingtok)
{
	if (child_pid == -1)
	{
		perror("child: error");
		exit (EXIT_FAILURE);
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