#include "hash_tables.h"
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/**
 * hash_table_print - function
 * @ht: hash table
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned int size;
	size_t index;
	char *key;
	char *value;
	int have_printed_an_item;

	index = 0;
	size = ht->size;
	have_printed_an_item = FALSE;

	printf("%s", "{");

	for (index = 0; index < size; index++)
	{
		if (ht->array[index])
		{
			key = ht->array[index]->key;
			value = ht->array[index]->value;

			if (have_printed_an_item)
				printf("%s", ", ");

			printf("'%s': '%s'", key, value);
			have_printed_an_item = TRUE;
		}
	}

	printf("%s\n", "}");

}
