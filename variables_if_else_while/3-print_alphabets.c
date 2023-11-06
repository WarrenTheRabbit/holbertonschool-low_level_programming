#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	print_lowercase_alphabet();
	print_uppercase_alphabet();
	putchar('\n');

	return (EXIT_SUCCESS);	
}


/**
 * main - entry point
 * Return: 0
 */
void print_lowercase_alphabet()
{
	int start_letter = 'a'; 
	int end_letter = 'z';
	int current_letter = start_letter;

	while (current_letter <= end_letter)
	{
		putchar(current_letter);
		current_letter++;
	}
}


/**
 * main - entry point
 * Return: 0
 */
void print_uppercase_alphabet()
{
	int start_letter = 'A'; 
	int end_letter = 'Z';
	int current_letter = start_letter;

	while (current_letter <= end_letter)
	{
		putchar(current_letter);
		current_letter++;
	}
}
