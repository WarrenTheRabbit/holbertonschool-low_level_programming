#include "main.h"

/**
 * create_array - task 0
 * @size - unsigned int
 * @c - char
 * Return - pointer to char
 */
char *create_array(unsigned int size, char c)
{
	char *ptr = NULL;

	if (size == 0)
	{
		return (NULL);
	}
	ptr = malloc(1);
	return (ptr);
}

