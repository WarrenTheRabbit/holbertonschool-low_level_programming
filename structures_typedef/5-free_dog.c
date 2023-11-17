#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory
 * @dog: dog data type
 */
void free_dog(dog_t *dog) {
    if (dog != NULL) {
        free(dog->name);   
        free(dog->owner); 
        free(dog);
    }
}

