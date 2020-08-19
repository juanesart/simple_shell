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
	size_t strsize = 0; /*variabe to getline int size type*/
	pid_t child_pid; /*variable to fork*/
	int sw, aw = 0;  /*variable to wait*/
	char *aux, *temp, **savingtok = NULL, *string = NULL;
	struct stat st;
	list_t *h = NULL, *auxh = NULL, *hreset = NULL;
	h = _getenv(env, h);
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
			if (aux != NULL)
			{
				if (*aux == '/')
				{
					savingtok = tokens(aux, temp);
					aw = 1;
				}
				else
					savingtok = tokens(aux, temp);
				if (stat(savingtok[0], &st) == 0)
				{
					child_pid = fork();
                                        fork_process(child_pid, savingtok);
					sw = 1;
				}
				else if (h->next == NULL)
				{
					if (sw != 1 && aux != NULL)
						printf(" %s: command not found [%d]\n", aux, sw);
				}
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
        _free(savingtok);
        free_list(h);
	free(string);
	return (0);
}