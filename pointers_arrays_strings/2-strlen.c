#include <stdio.h>

/**
 * _strlen - gets the length of the string
 * @s: a string
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length = 0;
	while (*s)
	{
		length++;
		s++;
	}

	return (length);
}
