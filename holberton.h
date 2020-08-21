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
#include <limits.h>
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
extern char **environ;
void _free(char **string);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
char **tokens(char *string);
char *_getenv(char *name);
int fork_process(pid_t child_pid, char *string, char **savingtok);
int command_D(int ret, char *string);
char *_cont(char *str1, char *str2);
int _path(char **argv);
int _strlen(char *s);

#endif
