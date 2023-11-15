#include <stdio.h>
#include "main.h"
size_t _get_size(char *str);


/**
 * puts_half - entry point
 * @str: pointer to char
 */
void puts_half(char *str)
{
	size_t size = _get_size(str);
	size_t midpoint = (size + 1) / 2;
	size_t i = midpoint;

	while (i < size)
	{
		_putchar(str[i]);	
		i++;
	}
	
	_putchar('\n');
}

/**
 * _get_size - returns size of string
 * @str: pointer to char
 * Return: size of string
 */
size_t _get_size(char *str)
{
	size_t count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}

	return (count);
}


