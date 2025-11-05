#include "main.h"
#include <stdlib.h>

/**
* count_words - Counts the number of words in a string
* @str: The string to count words in
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
* strtow - Splits a string into words
* @str: The string to split
*
* Return: pointer to an array of strings, or NULL on failure
*/
char **strtow(char *str)
{
char **words;
int word_count, word_len, i, j, k;

if (str == NULL || *str == '\0')
return (NULL);

word_count = count_words(str);
if (word_count == 0)
return (NULL);

words = malloc(sizeof(char *) * (word_count + 1));
if (words == NULL)
return (NULL);

i = 0;
j = 0;
while (str[i] && j < word_count)
{
while (str[i] == ' ')
i++;

word_len = 0;
while (str[i + word_len] && str[i + word_len] != ' ')
word_len++;

words[j] = malloc(sizeof(char) * (word_len + 1));
if (words[j] == NULL)
{
for (k = 0; k < j; k++)
free(words[k]);
free(words);
return (NULL);
}

for (k = 0; k < word_len; k++)
words[j][k] = str[i + k];
words[j][word_len] = '\0';

i += word_len;
j++;
}

words[word_count] = NULL;
return (words);
}
