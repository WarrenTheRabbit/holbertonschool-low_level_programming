#include <stddef.h>
#ifndef DOG_H
#define DOG_H

/**
 * struct dog - data structure
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};


typedef struct dog dog_t;

size_t _strlen(char *str);
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif

