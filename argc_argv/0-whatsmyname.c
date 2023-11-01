#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point of program
 * @argc: the count of the command line arguments
 * @argv: an array of size `argc` that stores the command line arguments
 * Return: Always return success message.
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (EXIT_SUCCESS);
}
