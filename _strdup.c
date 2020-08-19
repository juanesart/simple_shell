#include "holberton.h"

/**
*_strdup - string duplicate.
*@str: string to be duplicated.
*Return: 0.
**/

char *_strdup(const char *str)
{
	unsigned int len = 0, len2 = 0;
	char *str2;

	if (!str)
	{
		return (NULL);
	}
	while (str[len])
	{
		len++;
	}

	str2 = malloc((len + 1) * sizeof(char));

	if (!str2)
	{
		return (NULL);
	}

	while (len2 < len)
	{
		str2[len2] = str[len2];
		len2++;
	}
		str2[len2 + 1] = str[len2 + 1];
	return (str2);
}