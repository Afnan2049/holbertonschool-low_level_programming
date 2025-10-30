#include "main.h"

/**
* sqrt_helper - Helper function to find square root
* @n: The number to find square root of
* @guess: Current guess for the square root
*
* Return: The natural square root, or -1 if not found
*/
int sqrt_helper(int n, int guess)
{
/* Check if guess squared would overflow before calculating */
if (guess > n / guess)
return (-1);

/* Base case: if guess is the square root */
if (guess * guess == n)
return (guess);

/* Recursive case: try next integer */
return (sqrt_helper(n, guess + 1));
}

/**
* _sqrt_recursion - Returns the natural square root of a number
* @n: The number to find square root of
*
* Return: The natural square root, or -1 if not found
*/
int _sqrt_recursion(int n)
{
/* Handle edge cases */
if (n < 0)
return (-1);

if (n == 0 || n == 1)
return (n);

/* Start searching from 1 */
return (sqrt_helper(n, 1));
}

