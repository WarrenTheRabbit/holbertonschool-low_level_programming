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
	size_t index;
	char *key, *value;
	hash_node_t *current_node;
	int have_printed_an_item;

	if (!ht)
		return;
	index = 0;
	have_printed_an_item = FALSE;
	printf("%s", "{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index])
		{
			current_node = ht->array[index];
			while (current_node)
			{

				key = current_node->key;
				value = current_node->value;

				if (have_printed_an_item)
					printf("%s", ", ");

				printf("'%s': '%s'", key, value);
				have_printed_an_item = TRUE;
				current_node = current_node->next;
			}
		}
	}

	printf("%s\n", "}");

}
