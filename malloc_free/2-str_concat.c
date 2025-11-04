#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated space containing s1 + s2 + '\0'
 * NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
        char *concat; /* declaring pointer for new concated string */
        int len1, len2; /* variables to store lengths of strings */

        if (s1 == NULL) /* if string1 or string2 is null; treat as empty string*/
		s1 = "";
        if (s2 == NULL)
                s2 = "";

        len1 = strlen(s1); /* calculate length of string1 and s2, excludig null terminator */
        len2 = strlen(s2);

        concat = malloc(len1 + len2 + 1); /* allocate memory for: s1 chars + s2 char + null terminator*/
       if (concat == NULL)
	       return (NULL);

       strcpy(concat, s1)

	strcpy(concat, s2);

       return (concat);
}

