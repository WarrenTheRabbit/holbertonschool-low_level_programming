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
	char *ptr, *start = NULL;

	if (s1)
	{
		while (s1[index])
		{
			index++;
			s1_length++;
		}
	
		index = 0;
	}


	if (s2)
	{
		while (s2[index])
		{
			index++;
			s2_length++;
		}

		index = 0;
	}


	start = ptr = malloc(s1_length + s2_length + 1);
	
	if (ptr == NULL)
	{
		return (NULL);
	}

	if (s1)
	{
		while (*s1 != '\0')
		{
			*ptr++ = *s1++;
		}
	}


	if (s2)
	{
		while (*s2 != '\0')
		{
			*ptr++ = *s2++;
		}

	}


	*ptr = '\0';


	return (start);
}
