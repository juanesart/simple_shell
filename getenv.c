#include "holberton.h"
/**
 * _getenv - function that gets all PATH line
 * @name: environment variable to find
 * Return: Array of PATH line
 */
char *_getenv(char *name)
{
	int i = 0;
	char *ret;

	while (environ[i] != NULL)
	{
		ret = strtok(environ[i], "=");
		if (_strcmp(ret, name) == 0)
		{
			ret = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ret);
}
