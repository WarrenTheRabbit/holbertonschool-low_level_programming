#include <stdio.h>

/**
 * main - Entry point
 * Prints the mod 10 of an integr and the negative of itself.
 *
 * This function is a quick test of the % operator for extracting
 * the last digit of a decimal number.
 * 
 */
int main(void)
{

	int last_digit_of_positive_number = 19 % 10;
	int last_digit_of_negative_number = -19 % 10;

	printf("19 % 10 = %d\n", last_digit_of_positive_number);
	printf("-19 % 10 = %d\n", last_digit_of_positive_number);

	last_digit_of_positive_number = 9 % 10;
        last_digit_of_negative_number = -9 % 10;

        printf("9 % 10 = %d\n", last_digit_of_positive_number);
        printf("-9 % 10 = %d\n", last_digit_of_positive_number);
}
