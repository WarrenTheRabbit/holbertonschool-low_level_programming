#include <stdio.h>
#include "main.h"


void _reverse_recurse(char *s);

/**
 * _print_rev_recursion - prints string in reverse
 * @s: string to be reversed
 *
 */
void _print_rev_recursion(char *s)
{
	_reverse_recurse(s);
}


/**
 * _print_rev_recursion - prints string in reverse
 * @s: string to be reversed
 *
 */
void _reverse_recurse(char *s) 
{
        if (*s == '\0')
        {
                return;
        }
        else
        {
                _reverse_recurse(++s);
                _putchar(*s);
        }
}
