#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> /*Exit*/
#include <sys/wait.h>/*wait*/
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "holberton.h"

void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}

size_t print_list(const list_t *h)
{
	int count = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", h->len, h->str);
		}
		count++;
		h = h->next;
	}
	return (count);
}

list_t *add_node2(list_t **head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = strdup(str);
	add->len = strlen(str);
	add->next = *head;
	*head = add;

	return (add);
}

list_t *add_node(list_t ***head, const char *str)
{
	list_t *add;

	add = malloc(sizeof(list_t));
	if (add == NULL)
		return (NULL);
	add->str = strdup(str);
	add->len = strlen(str);
	add->next = **head;
	**head = add;

	return (add);
}

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
		args = strdup(token);
		strcat(args, "/");
		token = strtok(NULL, ": \t");
		add_node(&head, args);
		i++;
	}
free(dup);
return (args);
}

int main(int ac, char **av, char **env)
{
	char *string = NULL; /*variabe to get command keyboard*/
	size_t strsize = 0; /*variabe to getline int size type*/
	pid_t child_pid; /*variable to fork*/
	int status, sw, aw = 0;  /*variable to wait*/
	char *straux;
	char *aux;
	struct stat st;
	unsigned int i = 0, j = 0, k = 1;
	char *path = "PATH=";
	list_t *h = NULL;
	list_t *auxh = NULL;
	list_t *hreset = NULL;
	char *temp;
	char *auxt[1024];
        char *test[1024];

	/* str[1] = NULL; */
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
                aux = strtok(string, "\n");
		test[0] = (straux = strtok(string, " \n"));
                while (straux != NULL)
                {
                        test[k] = (straux = strtok(NULL, " \n"));
                        k++;
                }
		/* straux = strdup(aux);
                strtok(straux, " "); */
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
				if (*test[0] == '/')
				{
					/* auxt = malloc(sizeof(aux)); */
					*auxt = test[0];
                                        if (test[1] != NULL)
                                                auxt[1] = test[1];
                                        else
                                                auxt[1] = NULL;
					aw = 1;
				}
				else
				{
					/* auxt = malloc(sizeof(strcat(temp, aux))); */
					*auxt = strcat(temp, test[0]);
                                        if (test[1] != NULL)
                                                auxt[1] = test[1];
                                        else
                                                auxt[1] = NULL;
                                        /* *auxt + 1 =  */
                                        /* test = malloc(sizeof(strcat(temp, straux)));
                                        *test = strcat(temp, straux); */
				}
			}
			else
			{
				/* auxt = malloc(sizeof(test)); */
			}
                        /* printf("%s", aux);
                        printf("[%s]", test[0]);
                        printf("[%s]", test[1]); */
			if (stat(auxt[0], &st) == 0 && aux != NULL)
			{
                                /* printf("%s", straux); */
				child_pid = fork();
				if (child_pid == -1)
				{
					perror("child: error");
					exit (1);
				}
				if (child_pid == 0)
				{
                                        printf("%s", *auxt);
					if (execve(auxt[0], auxt, NULL) == -1)
					{
						perror("execve: error");
						exit(1);
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
                k = 1;
		aw = 0, sw = 0;
		sw = 0;
		h = hreset;
		printf("$ ");
	}
	/* free(auxt); */
	free(string);
	return (0);
}