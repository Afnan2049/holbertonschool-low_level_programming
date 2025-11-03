#include "main.h"
#include <stdlib.h>

/**
* _strdup - returns a pointer to a newly allocated space in memory,
* 	which contains a copy of the string given as a parameter
* @str: string to duplicate
*
* Return: pointer to duplicated string, or NULL if str = NULL or insufficient memory
*/
char *_strdup(char *str)
{

char *duplicate;
unsigned int i, length = 0;

/* Return NULL if str is NULL */
if (str == NULL)
return (NULL);


/* Calculate the length of the string manually */
while (str[length] != '\0')
length++;

/* Allocate memory for duplicate (length + 1 for null terminator) */
duplicate = malloc(sizeof(char) * (length + 1));

/* Return Null if malloc fails */
if (duplicate == NULL)
return (NULL);

/* Copy each character manually */
for (i = 0; i <= length; i++)
duplicate[i] = str[i];

return (duplicate);
}
