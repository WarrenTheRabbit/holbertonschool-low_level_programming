
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Override the malloc function.
 */
void *malloc(size_t size)
{
	return (NULL);
}

/**
 * Test function.
 */
void test_malloc_failure()
{
	char *array = create_array(10, 'a');
	if (array == NULL)
	{
		printf("Returns NULL when malloc fails.");
	}
	else 
	{
		printf("Does not return NULL when malloc fails.");
		free(array);
	}
}

int main(void)
{
	test_malloc_failure();
	return (0);
}
