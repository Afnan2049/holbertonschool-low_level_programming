#include "main.h"
#include <stdlib.h>
#include <string.h>


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
        char *concat;
        int len1, len2;


        if (s1 == NULL)
		s1 = "";
        if (s2 == NULL)
		s2 = "";


        len1 = strlen(s1);
	len2 = strlen(s2);


        concat = malloc(sizeof(char) * (len1 + len2 + 1));
			
	if (concat == NULL)
		return (NULL);
	       
	       
	       strcpy(concat, s1);
	       
	       strcat(concat, s2);


       return (concat);
}

