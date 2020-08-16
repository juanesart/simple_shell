#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> /*Exit*/
#include <sys/wait.h>/*wait*/
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

size_t print_list(const list_t *h);
list_t *add_node(list_t ***head, const char *str);
char *split(char *name, list_t **head);
void free_list(list_t *head);
list_t *add_node2(list_t **head, const char *str);


#endif