#include "main.h"


/**
 * is_prime_number - determines whether a number is prime
 * @n: number to check if prime
 * Return: 1 if n is prime; 0 if not prime
 */
int is_prime_number(int n)
{
	return (check_divisibility_recursively(n, 2));
}


/**
 * check_divisibility_recursively - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int check_divisibility_recursively(int n, int divisor)
{
	if (n <= 1 || is_currently_divisible(n, divisor) )
	{
		return (0);
	}
	if (have_tried_all_divisors(n, divisor) )
	{
		return (1);
	}

	return (check_divisibility_recursively(n, divisor + 1));

}



/**
 * is_currently_divisible - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int is_currently_divisible(int n, int divisor)
{
	return (n % divisor == 0) ? 1 : 0;
	
}

/**
 * have_tried_all_divisors - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int have_tried_all_divisors(int n, int divisor)
{
	return ((divisor * divisor) > n ) ? 1 : 0;
}

