#ifndef HEADER
#define HEADER
	#include <limits.h>
	#include <stddef.h>
	#include <string.h>	
	#include <stdlib.h>
	#include <stdio.h>
	typedef struct list_t list_t;

	struct list_t 
	{
		char *str;		
		unsigned int len;
		list_t *next;
	};

	/**
	 * struct dlistint_t - doubly linked list
	 * @n: integer
	 * @prev: points to the previous node
	 * @next: points to the next node
	 *
	 * Description: doubly linked list node structure
	 *
	 */
	typedef struct dlistint_t
	{
		int n;
		struct dlistint_t *prev;
		struct dlistint_t *next;
	} dlistint_t;


	size_t list_len(const list_t *h);
	int _putchar(char c);
	list_t *add_node(list_t **head, char *str);
	size_t print_list(const list_t *h);
	list_t *add_node_end(list_t **head, char const *str);
	void free_list(list_t *head);
	size_t print_dlistint(const dlistint_t *h);
	size_t dlistint_len(const dlistint_t *h);
	dlistint_t *add_dnodeint(dlistint_t **head, const int n);
	dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
	void free_dlistint(dlistint_t *head);
	dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
	int sum_dlistint(dlistint_t *head);
	dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
#endif

