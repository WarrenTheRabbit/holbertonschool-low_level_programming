#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int get_last_digit(int number);

/**
 * main - Entry point of program
 * Return: Always 0 (Success)
 */
int main(void)
{

	int n, last_digit;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_digit = get_last_digit(n);

	if (last_digit > 5)
	{
		printf("Last digit of %d is %d and is greater than 5\n",
			n, last_digit);
	}
	else if (last_digit < 6 && last_digit != 0)
	{
		printf("Last digit of %d is %d and is less than 6 and not 0\n",
			n, last_digit);
	}
	else
	{
		printf("Last digit of %d is %d and is 0\n", n, last_digit);
	}

	return (0);
}


/**
 * get_last_digit - returns last digit of an integer and retains original
 * 		    number's sign.
 * @number: The integer to extract the last digit and sign from.
 * Return: Last digit and sign of `number` such that the digits `abc`
 * returns `c` and `-abc` returns `-c`.
 */
int get_last_digit(int number)
{
	int last_digit = number % 10;

	return (last_digit);
}
