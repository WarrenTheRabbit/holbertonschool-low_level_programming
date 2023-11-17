#include "dog.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
size_t _strlen(char *str);
char *_strncpy(char *dest, char *src, int n);
/**
 * new_dog - initialises a dog by reference
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer to struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog = malloc(sizeof(dog_t));

	if (dog == NULL)
	{
		return (NULL);
	}

	if (name != NULL)
	{
		dog->name = malloc(_strlen(name) + 1);
		if (dog->name == NULL)
		{
			free(dog);
			return (NULL);
		}
		_strncpy(dog->name, name, _strlen(name));
	}
	else
	{
		dog->name = NULL;
	}

	if (owner != NULL)
	{
		dog->owner = malloc(_strlen(owner) + 1);
		if (dog->owner == NULL)
		{
			free(dog);
			return (NULL);
		}
		_strncpy(dog->owner, owner, _strlen(owner));
	}
	else
	{
		dog->owner = NULL;
	}


	dog->age = age;

	return (dog);

}


/**
 * _strncpy - description
 * @dest: pointer to char
 * @src: pointer to char
 * @n: int
 * Return: pointer to char
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for ( ; i < n ; i++)
	{
		dest[i] = '\0';
	}

	return (dest);

}


size_t _strlen(char *str)
{
	size_t count = 0;
	size_t length = 0;

	while (*str)
	{
		str++;
		count++;
	}

	length = count;

	return (length);
}

