#include "holberton.h"

int _path(char **argv)
{
	char *path = NULL;
	char *str = NULL;
	struct stat st;
	unsigned int i;

	path = _getenv("PATH");
	path = strtok(path, ":");
	i = 0;
	while (path != NULL)
	{
		str = _cont(path, argv[0]);
		if (stat(str, &st) == 0)
		{
			argv[0] = _strdup(str);
			break;
		}
		path = strtok(NULL, ":");
		i++;
	}
	free(str);
	if (execve(argv[0], argv, NULL) == -1)
		return (-1);
	return (0);
}

char *_cont(char *str1, char *str2)
{
	int len1, len2, i = 0, b = 0;
	char *newstr;

	len1 = strlen(str1);
	len2 = strlen(str2);

	newstr = malloc((len1 + len2) + 1);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
        newstr[i] = '/';
	i++;
	while (str2[b] != '\0')
	{
		newstr[i] = str2[b];
		i++;
		b++;
	}
	newstr[i + 1] = '\0';
	return (newstr);
}