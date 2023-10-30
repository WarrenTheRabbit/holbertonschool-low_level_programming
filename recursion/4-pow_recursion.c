#include <stdio.h>
#include "main.h"


/**
 * _pow_recursion - calculates x raised to y
 * @n: base
 * @y: exponent
 * Return: n to the power of y
 */
int _pow_recursion(int n, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
	return (n * _pow_recursion(n, y - 1));
	}

}
