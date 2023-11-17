#include "main.h"
#include "main.h"
#include <stddef.h>
/**
 * _strncpy - description
 * @dest: pointer to char
 * @src: pointer to char
 * @n: int
 * Return: pointer to char
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for ( ; i < n ; i++)
	{
		dest[i] = '\0';
	}

	return (dest);

}
