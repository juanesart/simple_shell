#include "holberton.h"
list_t *_getenv(list_t *h)
{
        char *path = "PATH=";
        unsigned int i = 0, j = 0;
while (environ[i] != NULL)
	{
		if (*environ[i] == path[j])
		{
			split(environ[i], &h);
			break;
		}
		i++;
	}
return (h);
}