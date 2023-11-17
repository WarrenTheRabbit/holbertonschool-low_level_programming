#include "function_pointers.h"

/**
 * print_name - something
 * @name: pointer to char
 * @f: function that takes a pointer to char
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
