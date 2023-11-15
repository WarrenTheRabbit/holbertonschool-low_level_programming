#include <stdio.h>
#include "main.h"
void _swap_elements(char *a, char *b);
size_t _get_size(char *s);
/**
 * rev_string - entry point
 * @s: pointer to char
 * Return: Always 0.
 */
void rev_string(char *s)
{

	size_t size = _get_size(s);
	size_t i = 0;

	for (i = 0; i < size / 2; i++)
	{
		_swap_elements(&s[i], &s[size - 1 - i]);
	}

}

/**
 * _get_size - gets the number of elements
 * @s: pointer to character
 * Return: the number of elements
 */
size_t _get_size(char *s)
{
	size_t count = 0;

	while (*s != '\0')
	{
		s++;
		count++;
	}

	return (count);
}

/**
 * _swap_elements - swaps the char values of two memory addresses
 * @a: memory address
 * @b: memory address
 * Return: void
 */
void _swap_elements(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
