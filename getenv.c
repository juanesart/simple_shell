#include "holberton.h"
char *_getenv(char *name)
{
	int i = 0;
	char *ret;

	while (environ[i] != NULL)
	{
		ret = strtok(environ[i], "=");
		if (_strcmp(ret,name) == 0)
		{
			ret = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ret);
}