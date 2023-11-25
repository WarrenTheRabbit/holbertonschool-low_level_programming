
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
	size_t index = 0;

	ptr = malloc(1);

	if (ptr == NULL)
	{
		return (NULL);
	}

	while ( str[index] )
	{
		ptr[index] = str[index];
		index++;
	}

	return (ptr);
}

