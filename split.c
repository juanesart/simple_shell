#include "holberton.h"

char *split(char *name, list_t **head)
{
	char *token = NULL;
	char *dup;
	size_t i;
	char *args = NULL;
	dup = malloc(strlen(name));
	if (dup == NULL)
		return (0);
	strcpy(dup, name);
	token = strtok(dup, "PATH=: \t");
	i = 0;
	while (token)
	{
		args = _strdup(token);
		strcat(args, "/");
		token = strtok(NULL, ": \t");
		add_node(&head, args);
		i++;
		free(args);
	}
free(dup);
return (NULL);
}