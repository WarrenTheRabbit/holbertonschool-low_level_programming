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
	unsigned int index;

	if (size == 0)
	{
		return (NULL);
	}
	
	ptr = malloc(size * sizeof(c));
	
	for (index = 0 ; index < size; index++)
	{
		ptr[index] = c;
	}
		
	return (ptr);
}

