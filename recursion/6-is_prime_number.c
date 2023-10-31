#include "main.h"


/**
 * is_prime_number - determines whether a number is prime
 *
 * @n: number to check if prime
 *
 * Return: 1 if n is prime; 0 if not prime
 */
int is_prime_number(int n)
{
	return (_is_prime_number(n, 2));
}

/**
 * _is_prime_number - determines whether a number is prime
 *
 * Description: Recursively calculates whether `n` is prime;
 * this is achieved by iteratively testing candidate
 * divisors.
 *
 * @n: The number to check for primacy.
 * @divisor: The current candidate divisor.
 *
 * Return: 1 if n is prime; 0 if not prime.
 */
int _is_prime_number(int n, int divisor)
{
	if (is_conclusively_not_prime(n, divisor))
	{
		return (0);
	}
	if (is_conclusively_prime(n, divisor))
	{
		return (1);
	}

	return (_is_prime_number(n, divisor + 1));
}

/**
 * _is_prime_number - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int is_conclusively_not_prime(int n, int divisor)
{
	if (n <= 1 || is_currently_divisible(n, divisor))
	{
		return (1);
	}
	else
	{
		return (0);
	}	
}

/**
 * _is_prime_number - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int is_conclusively_prime(int n, int divisor)
{
	if (have_tried_all_divisors(n, divisor))
	{
		return (1);
	}
	else
	{
		return (0);
	}	
}

/**
 * is_currently_divisible - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int is_currently_divisible(int n, int divisor)
{
	return (n % divisor == 0 ? 1 : 0);

}

/**
 * have_tried_all_divisors - determines whether a number is prime
 * @n: number to check if prime
 * @divisor: current divisor
 * Return: 1 if n is prime; 0 if not prime
 */
int have_tried_all_divisors(int n, int divisor)
{
	return ((divisor * divisor) > n ? 1 : 0);
}

