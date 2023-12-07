#include "hash_tables.h"


/**
 * hash_table_create - function
 * @size: size of hash table
 * Return: HashTable
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	hash_node_t **array = NULL;

	hash_table = malloc(sizeof(*hash_table));

	if (hash_table == NULL)
	{
		return (NULL);
	}

	hash_table->array = malloc(sizeof(*array) * size);

	if (hash_table->array == NULL)
	{
		free(hash_table);
		return (NULL);
	}

	hash_table->size = size;

	return (hash_table);
}
