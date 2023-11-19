#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *buffer;

    buffer = create_array(0, 'H');
    if  (buffer == NULL)
    {
        printf("Returns NULL when size is 0.");
        return (1);
    }
    free(buffer);
}
