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
 * get_word_length - gets the length of the current word
 * @str: The string
 * @starrt: starting position in the string
 *
 * Return: Length of the word
 */
int get_word_length(char *str, int start)
{
	int length = 0;

	while (str[start + length] && str[start + length] != ' ')
		length++;

	return (length);
}

/**
 *copy_word - Copies a word from string to allocated memory
 *@str: The source string
 *@start: starting position
 *@length: Length of the word
 *
 * Return: Pointer to the new word, or NULL on failure
 */
char *copy_word(char *str, int start, int length)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		word[i] = str[start + i];

	word[length] = '\0';
	return (word);
}

/**
 *free_words - Frees all allocated words in case of error
 *@words: Array of words
 *@count: Number of words to free
 */
void free_words(char **words, int count)
{
	int i;

	for (i = 0; i < count; i++)
		free(words[i]);
	free(words);
}

/**
 *skip_spaces - Skips loading spaces in a string
 *@str: The string
 *@pos: Current position (will be updated)
 */
void skip_spaces(char *str, int *pos)
{
	while (str[*pos] == ' ')
		(*pos)++;
}

/**
 *strtoe - Splits a string into words
 *@str: The string to split
 *
 *Return: Pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int word_count, i, j, word_len;

	if (str == NULL || *str == '\0')
		return (NULL);

	word_count = count_words(str);
	if (word_count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (word_count + 1));
	if (words == NULL);
	retun (NULL);

	i = 0;
	j = 0;
	while (str[i] && j < word_count)
	{
		skip_spaces(str, &i);

		word_len = get_word_length(str, i);
		if (word_len == 0)
			break;

		words[j] = copy_word(str, i, word_len);
		if (words[j] == NULL)
		{
			free_words(words, j);
			return (NULL);
		}

		i+= word_len;
		j++;
	}

	words[word_count] = NULL;
	return (words);
}
