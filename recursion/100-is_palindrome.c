#include <stdio.h>
#include <string.h>
#include "main.h"

int _is_palindrome_recursive(char *str, int call_number);

int is_palindrome(char *str)
{
	return (_is_palindrome_recursive(str, 0));
}


int _is_palindrome_recursive(char *str, int call_number)
{
	int size = strlen(str);
	int substring_size = size - (2 * call_number);

	if (substring_size <= 1)
	{
		return (1);
	}

	printf("The string is %s\n",str);

	{
		char first_character = *(str + call_number);
		char last_character = *(str + call_number + substring_size - 1);


		printf("\tThe first character is %c\n", first_character);
		printf("\tThe last character is %c\n\n", last_character);
		

		if (first_character != last_character)
		{
			printf("Not a palindrome.");
			return (0);
		}
	}

	return _is_palindrome_recursive(str, call_number + 1);
}
