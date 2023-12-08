#include "hash_tables.h"

/**
 * hash_table_get - function
 * @ht: hash table
 * @key: key to search
 * Return: value or NULL if key couldn't be found
 */
char *hash_table_get(hash_table_t const *ht, char const *key)
{
	unsigned long int index;
	hash_node_t *node_at_key;

	if (ht == NULL)
		return (NULL);

	index = key_index((unsigned char const *)key, ht->size);
	node_at_key = ht->array[index];

	while (node_at_key)
	{
		if (strcmp(node_at_key->key, key) == 0)
		{
			return (node_at_key->value);
		}

		node_at_key = node_at_key->next;
	}

	return (NULL);
}
