#include "main.h"
/**
	* _strlen - returns length of string
	* @s: pointer to char
	* Return: lengh of string
	*/
int _strlen(char const *s)
{
	char const *start = s;
	char const *current = s;

	while (*current)
	{
	current++;
	}
	return (current - start);
}

/**
* str_concat - concatenates two strings
* @s1: pointer to char
* @s2: pointer to char
* Return: pointer to char
*/
char *str_concat(char *s1, char *s2)
{
	size_t s1_length = 0;
	size_t s2_length = 0;
	char *current = NULL;
	char *start = NULL;

	if (s1)
		s1_length = _strlen(s1);

	if (s2)
		s2_length = _strlen(s2);

	start = current = malloc(s1_length + s2_length + 1);

	if (current == NULL)
		return (NULL);

	if (s1)
	{
		while (*s1 != '\0')
			*current++ = *s1++;
	}
	if (s2)
	{
		while (*s2 != '\0')
			*current++ = *s2++;
	}

	*current = '\0';
	return (start);
}
