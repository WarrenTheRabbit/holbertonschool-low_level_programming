#ifndef HEADER
#define HEADER
	#include <stddef.h>
	int _putchar(char c);
	typedef struct list_t list_t;

	struct list_t
	{
		char *str;
		unsigned int len;
		list_t *next;
	};

	size_t print_list(const list_t *h);

#endif
