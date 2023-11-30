#ifndef HEADER
#define HEADER
	#include <stddef.h>
	#include <string.h>	
	#include <stdlib.h>

	typedef struct list_t list_t;

	struct list_t 
	{
		char *str;		
		unsigned int len;
		list_t *next;
	};

	size_t list_len(const list_t *h);
	int _putchar(char c);
	list_t *add_node(list_t **head, char *str);
	size_t print_list(const list_t *h);

#endif

