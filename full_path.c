#include "holberton.h"

int _path(char **argv)
{
	list_t *h = NULL;
	char *str = NULL;
        char *tmp = NULL;
	struct stat st;

	h = _getenv(h);
        /* print_list(h); */

	while (h)
	{
                tmp = h->str;
		str = _which(tmp, argv[0]);
                printf("%s", str);
		if (stat(str, &st) == 0)
		{
			argv[0] = str;
			break;
		}
		h = h->next;
                /* free(str); */
	}
        /* free_list(h); */
	/* free(str); */
	if (execve(argv[0], argv, NULL) == -1)
		return (-1);
        free(str);       
	return (0);
}

char *_which(char *str1, char *str2)
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
	while (str2[b] != '\0')
	{
		newstr[i] = str2[b];
		i++;
		b++;
	}
	newstr[i + 1] = '\0';
	return (newstr);
}