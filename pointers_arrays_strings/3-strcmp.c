#include "main.h"
#include "main.h"
#include <stddef.h>
/**
 * _strcmp - description
 * @dest: pointer to char
 * @src: pointer to char
 * Return: 0 if equal, negative or positive if not
 */
int _strcmp(char *s1, char *s2)
{

	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else 
			return (*s1 - *s2);		
	}

	return (0);

}
