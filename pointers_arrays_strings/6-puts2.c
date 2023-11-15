#include <stdio.h>
#include "main.h"

int _get_size(char *str);

/**
 * puts2 - entry point
 * @str:
 */
void puts2(char *str)
{
	size_t length = _get_size(str);
	size_t count;

	for (count = 0; count < length; count = count + 2)
	{
		_putchar(str[count]);
	}
	_putchar('\n');
}

/**
 * _get_size - gets the size
 * @str: pointer to string
 * Return: size of string
 */
int _get_size(char *str)
{
	size_t count = 0;

	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}
