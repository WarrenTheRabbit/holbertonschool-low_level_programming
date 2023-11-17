#include "main.h"
#include <stddef.h>
/**
 * _strcat - description
 * @dest: pointer to char
 * @src: pointer to char
 * Return: pointer to char
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}


	*ptr = '\0';

	return (dest);
}
