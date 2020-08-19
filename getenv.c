#include "holberton.h"
list_t *_getenv(char **env, list_t *h)
{
        char *path = "PATH=";
        unsigned int i = 0, j = 0;
while (env[i] != NULL)
	{
		if (*env[i] == path[j])
		{
			split(env[i], &h);
			break;
		}
		i++;
	}
return (h);
}