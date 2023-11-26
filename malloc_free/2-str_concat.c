#include "main.h"

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
	size_t index = 0;
	char *ptr = NULL;

	while (s1[index] && s2[index])
	{
		index++;
		s1_length++;
		s2_length++;
	}

	while (s1[index])
	{
		index++;
		s1_length++;
	}

	while (s2[index])
	{
		index++;
		s2_length++;
	}


	ptr = malloc(s1_length + s2_length + 1);
	
	if (ptr == NULL)
	{
		return (NULL);
	}

	index = 0;

	while (s1[index])
	{
		ptr[index] = s1[index];
		index++;
	}

	while (s2[index - s1_length])
	{
		ptr[index] = s2[index - s1_length];
		index++;
	}

	ptr[index] = s2[index - s1_length];


	return (ptr);
}
