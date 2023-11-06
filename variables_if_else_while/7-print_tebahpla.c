#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void print_reversed_alphabet(void);

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	print_reversed_alphabet();
	putchar('\n');

	return (EXIT_SUCCESS);
}


/**
 * print_reversed_alphabet - entry point
 * Return: 0
 */
void print_reversed_alphabet(void)
{
	int start_letter = 'z';
	int end_letter = 'a';
	int current_letter = start_letter;

	while (current_letter >= end_letter)
	{
		putchar(current_letter);
		current_letter--;
	}
}


