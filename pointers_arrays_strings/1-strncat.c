#include "main.h"
#include <stddef.h>
/**
 * _strncat - description
 * @dest: pointer to char
 * @src: pointer to char
 * Return: pointer to char
 */
char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;
	int index = 0;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0' && index < n)
	{
		*ptr++ = *src++;
		index++;
	}


	*ptr = '\0';

	return (dest);
}

