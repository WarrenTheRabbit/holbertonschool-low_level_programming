#include "hash_tables.h"

/**
 * hash_table_delete - function
 * @ht: hash table
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	size_t index = 0;
	hash_node_t *current_node, *next_node = NULL;

	if (!ht)
		return;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index])
		{
			current_node = ht->array[index];
			while (current_node)
			{
				next_node = current_node->next;
				free(current_node->key);
				free(current_node->value);
				free(current_node);
				current_node = next_node;
			}
		}
	}

	free(ht->array);
	free(ht);
}
