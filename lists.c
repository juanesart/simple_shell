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
	add->str = _strdup(str);
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
	add->str = _strdup(str);
	add->len = strlen(str);
	add->next = **head;
	**head = add;
	return (add);
}