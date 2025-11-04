#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of the program
 * @ac: argument count
 * @av: argument vector (array of strings)
 *
 * Return: pointer to new string, or NULL if failure
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int i, j, k = 0;
	int total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++);
		total_len += j + 1;
	}

	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
		str[k] = '\0';
		return (str);
}
