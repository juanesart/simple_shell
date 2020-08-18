#include "holberton.h"

char** tokens(char *string, char *temp)
{
	char **savingtok = NULL;
	char *token = NULL;
	int i = 0, ntok = 0;
	char *tmp = NULL;

        if (string == NULL)
                return (NULL);
        if (*string == '/')
        {
                tmp = string;
                token = strdup(tmp);
        }
        else
        {
	        tmp = strcat(temp, string);
                token = strdup(tmp);
        }
	tmp = strtok(tmp, " \n\t");
	while (tmp != NULL)
	{
		ntok++;
		tmp = strtok(NULL, " \n\t");
	}

	savingtok = (char **) malloc((ntok * sizeof(char *) + 1));
	token = strtok(token, " \n\t");
	while (token != NULL)
	{
		savingtok[i] = strdup(token);
		i++;
		token = strtok(NULL, " \n\t");
	}
	savingtok[ntok + 1] = '\0';


	free(token);
	return (savingtok);
}