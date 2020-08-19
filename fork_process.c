#include "holberton.h"

int fork_process(pid_t child_pid, char **savingtok)
{
	if (child_pid == -1)
	{
		perror("child: error");
		exit (EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(savingtok[0], savingtok, NULL) == -1)
		{
			perror("execve: error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}