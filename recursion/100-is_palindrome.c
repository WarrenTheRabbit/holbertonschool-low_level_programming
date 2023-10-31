#include <stdio.h>
#include <string.h>
#include "main.h"

int _is_palindrome_recursive(char *str, int call_number);

/**
 * is_palindrome - checks whether `str` is a palindrome.
 * @str: a string.
 * Return: 1 if `str` is a palindrome; otherwise, 0.
 */
int is_palindrome(char *str)
{
	return (_is_palindrome_recursive(str, 0));
}


/**
 * _is_palindrome_recursive - checks whether `str` is a palindrome.
 * @str: a string.
 * @call_number: counts how many calls have been made previously.
 * Return: 1 if `str` is a palindrome; otherwise, 0.
 */
int _is_palindrome_recursive(char *str, int call_number)
{
	int size = strlen(str);
	int substring_size = size - (2 * call_number);
	char first_character = *(str + call_number);
	char last_character = *(str + call_number + substring_size - 1);

	if (substring_size <= 1)
	{
		return (1);
	}
	else if (first_character != last_character)
	{
		return (0);
	}
	else
	{
		return (_is_palindrome_recursive(str, call_number + 1));
	}
}
