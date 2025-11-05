#include "main.h"
#include <stdlib.h>

/**
* count_words - Counts the number of words in a string
* @str: The string to count words in
*
* Return: Number of wordsin the string
*/
int count_words(char *str)
{
int count = 0, in_word = 0, i = 0;

if (str == NULL)
return (0);

while (str[i])
{
if (str[i] == ' ')
{
in_word = 0;
}
else if (!in_word)
{
in_word = 1;
count++;
}
i++;
}
return (count);
}

/**
* strtow - splits a string into words
* @str: the string to split
*
* Return: pointer to an array of strings (words), or NULL on failure
*/
char **strtow(char *str)
{
char **words;
int i = 0, j, k, len, wc, start;

if (str == NULL || *str == '\0')
return (NULL);

wc = word_count(str);
if (wc == 0)
return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
return (NULL);

for (k = 0; k < wc; k++)
{
while (str[i] == ' ')
i++;
start = i;
while (str[i] != ' ' && str[i] != '\0')
i++;
len = i - start;

words[k] = malloc(sizeof(char) * (len + 1));
if (words[k] == NULL)
{
while (k--)
free(words[k]);
free(words);
return (NULL);
}

for (j = 0; j < len; j++)
words[k][j] = str[start + j];
words[k][j] = '\0';
}
words[k] = NULL;

return (words);
}
