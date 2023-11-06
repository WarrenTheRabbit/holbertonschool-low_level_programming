#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int is_permitted_character(char character);
void print_lowercase_alphabt(void);

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	print_lowercase_alphabt();
	putchar('\n');
	return (EXIT_SUCCESS);
}


/**
 * is_permitted_character - function
 * @character: letter to check
 * Return: 1 if permitted; 0 otherwise
 *
 */
int is_permitted_character(char character)
{
	if (character == 'q' || character == 'e')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}


/**
 * print_lowercase_alphabt - entry point
 * Return: 0
 */
void print_lowercase_alphabt(void)
{
	int start_letter = 'a';
	int end_letter = 'z';
	int current_letter = start_letter;

	while (current_letter <= end_letter)
	{
		if (is_permitted_character(current_letter))
		{
			putchar(current_letter);
		}

	current_letter++;

	}
}

