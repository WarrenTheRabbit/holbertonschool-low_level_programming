#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void print_digits(void);

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	print_digits();
	print_lowercase_alphabet();
	putchar('\n');
	return (EXIT_SUCCESS);
}

/**
 * print_lowercase_alphabet - entry point
 * Return: 0
 */
void print_lowercase_alphabet(void)
{
	int start_letter = 'a';
	int end_letter = 'f';
	int current_letter = start_letter;

	while (current_letter <= end_letter)
	{
		putchar(current_letter);
		current_letter++;
	}
}


/**
 * print_digits - entry point
 * Return: 0
 */
void print_digits(void)
{
	int start_digit = '0';
	int end_digit = '9';
	int current_digit = start_digit;

	while (current_digit <= end_digit)
	{
		putchar(current_digit);
		current_digit++;
	}
}
