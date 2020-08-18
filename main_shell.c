#include "holberton.h"

void _free(char **string)
{
	size_t i = 0;

	if (string == NULL)
		return;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}


int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
	
	char *string = NULL; /*variabe to get command keyboard*/
	size_t strsize = 0; /*variabe to getline int size type*/
	pid_t child_pid; /*variable to fork*/
	int status, sw, aw = 0;  /*variable to wait*/
	char *aux;
	struct stat st;
	unsigned int i = 0, j = 0;
	char *path = "PATH=";
	list_t *h = NULL;
	list_t *auxh = NULL;
	list_t *hreset = NULL;
	char *temp;
        char **savingtok = NULL;
	while (env[i] != NULL)
	{
		if (*env[i] == path[j])
		{
			split(env[i], &h);
			break;
		}
		i++;
	}
	printf("$ ");
	while (getline(&string, &strsize, stdin) != EOF)
	{
                aux = _strtok(string, "\n");
		hreset = h;
		while (h)
		{
			add_node2(&auxh, h->str);
			h = h->next;
		}
		h = hreset;
		while (h)
		{
			temp = auxh->str;
                        if (*aux == '/')
                        {
                                savingtok = tokens(aux, temp);
                                aw = 1;
                        }
                        else
                                savingtok = tokens(aux, temp);
			
			if (stat(savingtok[0], &st) == 0 && aux != NULL)
			{
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("child: error");
					exit (EXIT_FAILURE);
				}
				if (child_pid == 0)
				{
					if (execve(savingtok[0], savingtok, NULL) == -1)
					{
						perror("execve: error");
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					wait(&status);
				}
				sw = 1;
			}
			else if (h->next == NULL)
			{
				if (sw != 1 && aux != NULL)
					printf(" %s: command not found [%d]\n", aux, sw);
			}
			if (sw == 1 && aw == 1)
				break;
			h = h->next;
			auxh = auxh->next;
		}
		aw = 0, sw = 0;
		sw = 0;
		h = hreset;
		printf("$ ");
	}
        /* _free(auxt);
        _free(test); */
        /* free(temp); */
        /* free_list(hreset); */
        free_list(h);
	free(string);
	return (0);
}