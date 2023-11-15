#include <stdio.h>
#include "main.h"
/**
 * _strcpy - task 9
 * @dest: a pointer to char
 * @src: a pointer to char
 * Return:  a pointer to char
 */
char *_strcpy(char *dest, char *src)
{

	size_t index = 0;

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}

	dest[index] = src[index];

	return (dest);

}
