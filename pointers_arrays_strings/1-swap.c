#include <stdio.h>
#include "main.h"
/**
 * swap_int - entry point
 * @a: number
 * @b: number
 * Return: Always 0.
 */
void swap_int(int *a, int *b)
{
	int a_value = *a;

	*a = *b;
	*b = a_value;
}
