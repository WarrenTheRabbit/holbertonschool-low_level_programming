#include "main.h"


/**
 * _sqrt_recursion - calculates x raised to y
 * @n: base
 * Return: n to the power of y
 */
int _sqrt_recursion(int n)
{
	return (_do_calculation(n, 1));
}

/**
 * _do_calculation - calculates x raised to y
 * @n: number
 * @y: number_to_square
 * Return: n to the power of y
*/
int _do_calculation(int n, int y)
{
	if (y * y == n)
	{
	return (y);
	}
	if (y * y > n)
	{
	return (-1);
	}

	return (_do_calculation(n, y + 1));
}
