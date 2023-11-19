
#include "main.h"

/**
 * _strdup - task 0
 * @size:  unsigned int
 * @c: char
 * Return: pointer to char
 */
char *_strdup(char *str)
{
	char *ptr = NULL;

	ptr = malloc(1);

	if (ptr == NULL)
	{
		return (NULL);
	}

	return (ptr);
}

