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
                token = _strdup(tmp);
        }
        else
        {
	        tmp = _strcat(temp, string);
                token = _strdup(tmp);
        }
	tmp = _strtok(tmp, " \n\t");
	free(token);
	while (tmp != NULL)
	{
		ntok++;
		tmp = _strtok(NULL, " \n\t");
	}

	savingtok = (char **) malloc((ntok * sizeof(char *) + 1));
	token = _strtok(token, " \n\t");
	while (token != NULL)
	{
		savingtok[i] = _strdup(token);
		i++;
		token = _strtok(NULL, " \n\t");
	}
	savingtok[ntok + 1] = '\0';


	free(token);
	return (savingtok);
}