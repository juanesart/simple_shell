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

int command_D(int ret, char *string)
{
	if (ret < 0)
	{
		if (isatty(0) == 1)
			write(1, "\n", 1);
		free(string);
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}

int main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	size_t MaxSize = INT_MAX; /*variabe to getline int size type*/
	pid_t child_pid; /*variable to fork*/
	int input;  /*variable to wait*/
	char **savingtok = NULL, *string = NULL, *ext = "exit\n";
	/* struct stat st; */
	/* list_t *h = NULL, *auxh = NULL, *hreset = NULL; */
	/*h = _getenv(env, h); 
	printf("$ "); */
	while (1)
	{
                if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#$ ", 3);
                input = getline(&string, &MaxSize, stdin);
                command_D(input, string);
                if (_strcmp(string, ext) == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
                child_pid = fork();
                if (fork_process(child_pid, string, savingtok) == -1)
                {
                        _free(savingtok);
			exit(EXIT_FAILURE);
                }
		/* aux = _strtok(string, "\n"); */
		/* hreset = h;
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
		h = hreset; */
	}
        /* _free(savingtok); */
        /* free_list(h); */
	free(string);
	return (0);
}