#include <stdlib.h>
#include "main.h"

/**
 * print_last_digit - writes the character c to stdout
 * @n: number
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_last_digit(int n)
{
	return (n % 10);
}
