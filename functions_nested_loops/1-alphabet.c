#include <stdlib.h>
#include "main.h"

/**
 * print_alphabet - writes the character c to stdout
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_alphabet(void)
{
	int start_letter = 'a';
	int count = 0;

	while (count < 26)
	{
		_putchar(start_letter + count);
		count++;
	}

	_putchar('\n');
}
