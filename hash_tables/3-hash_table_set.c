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
 * @ht:
 * @key: a key to be indexed to @ht
 * @value: a value to be stored at @key
 * Return: success message.
 */
int hash_table_set(hash_table_t *ht, char const *key, char const *value)
{
	unsigned long int index;
	hash_node_t *node;
	char *key_copy;
	char *value_copy;

	if (!ht)
	{
		return (0);
	}

	node = malloc(sizeof(*node));

	if (!node)
	{
		return (0);
	}

	key_copy = strdup(key);

	if (!key_copy)
	{
		free(node);
		return (0);
	}

	value_copy = strdup(value);

	if (!value_copy)
	{
		free(key_copy);
		free(node);
		return (0);
	}


	node->key = (char *) key_copy;
	node->value = (char *) value_copy;
	node->next = NULL;


	index = key_index((unsigned char const *)key, ht->size);

	if (ht->array[index])
	{
		if (!strcmp(ht->array[index]->key, node->key))
		{
			ht->array[index]->value = node->value;
		}
		else 
		{
			prepend(&ht->array[index], node);
		}
	}
	else
	{
		ht->array[index] = node;
	}

	return (1);


}
