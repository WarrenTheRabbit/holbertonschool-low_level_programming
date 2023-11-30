#include <stdio.h>

void __attribute__((constructor)) preMain();


/**
 * preMain - runs before Main
 * @void: nothing
 * Returns - void
 */
void preMain(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

