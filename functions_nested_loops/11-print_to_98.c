#include "main.h"

/**
 * print_number - prints an integer using _putchar
 * @n: the integer to print
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}

/**
 * print_to_98 - Prints all natural numbers from n to 98,
 * separated by a comma and a space.
 * @n: The starting number.
 */
void print_to_98(int n)
{
	int i;

	for (i = n; i != 98; )
	{
		print_number(i);
		_putchar(',');
		_putchar(' ');

		if (i < 98)
			i++;
		else
			i--;
	}

	print_number(98);
	_putchar('\n');
}
