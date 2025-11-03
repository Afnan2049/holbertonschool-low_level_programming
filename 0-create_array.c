#include "main.h"
#include <stdlib.h>

/**
* create_array - create am array of chars and initialize it with a specific char
* @size: size of the array to create
* @c: charecyer to initialize the array with
*
* Return: pointer to an array, or NULL if size = 0 or if malloc fails
*/
char *create_array(unsigned int size, char c)
{
char *array;
unsigned int i;

/* Return NULL if size is 0 */
if (size == 0)
return (NULL);

/* Allocate memory for the array */
array = malloc(sizeof(char) * size);

/* Return NULL if malloc fails */
if (array == NULL)
return (NULL);
/*initialize each element with the spicified char */
for (i = 0; i < size; i++)
array[i] = c;

return (array);
}

