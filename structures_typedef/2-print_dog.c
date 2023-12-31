#include "dog.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_dog - initialises a dog by reference
 * @d: dog struct
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");

}
