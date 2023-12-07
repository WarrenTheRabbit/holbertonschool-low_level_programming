#include "hash_tables.h"

/**
 * prepend - function
 * @list: linked list
 * @node: node to prepend
 * Return: nothing
 */
void prepend(hash_node_t **list, hash_node_t *node)
{
	if (list != NULL)
	{
		node->next = *list;
		*list = node;
	}
}


/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table
 * @key: a key to be indexed to @ht
 * @value: a value to be stored at @key
 * Return: success message.
 */
int hash_table_set(hash_table_t *ht, char const *key, char const *value)
{
	unsigned long int index;
	hash_node_t *node;

	node = malloc(sizeof(*node));

	if (!node)
	{
		return (-1);
	}

	node->key = (char *) key;
	node->value = (char *) value;
	node->next = NULL;


	index = key_index((unsigned char const *)key, ht->size);

	if (ht->array[index])
	{
		prepend(&ht->array[index], node);
	}
	else
	{
		ht->array[index] = node;
	}

	return (1);


}
