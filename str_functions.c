#include "holberton.h"
/**
 * _strcat - concat strings *
 * @dest: destination string
 * @src: source string
 * Return: returns string
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	return (dest);
}


/**
 * _strncpy - copies a string
 * @dest: destination string
 * @src: source string
 * @n: number of chars
 * Return: returns destination string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i != n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i != n)
				dest[i++] = '\0';
			break;
		}
		i++;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: difference
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((s1[i] - '0') - (s2[i] - '0'));
		i++;
	}
	return (0);
}

char *_strtok(char *str, const char *delim)
{
	static char *aux;
	int ch;

	if (str == 0)
	str = aux;
	do {
	if ((ch = *str++) == '\0') 
		return 0;
	} while (strchr(delim, ch));
	--str;
	aux = str + strcspn(str, delim); 
	if (*aux != 0) 
		*aux++ = 0; 
	return str; 
}