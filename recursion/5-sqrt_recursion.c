#include "main.h"

/**
 * sqrt_helper - Helper function to find square root using binary search
 * @n: The number to find square root of
 * @low: Lower bound for search
 * @high: Upper bound for search
 *
 * Return: The natural square root, or -1 if not found
 */
int sqrt_helper(int n, int low, int high)
{
    int mid;

    /* Base case: if search range is invalid */
    if (low > high)
        return (-1);

    mid = low + (high - low) / 2;

    /* Check if mid is the square root */
    if (mid * mid == n)
        return (mid);
    
    /* If mid squared is less than n, search right half */
    if (mid * mid < n)
        return (sqrt_helper(n, mid + 1, high));
    
    /* If mid squared is greater than n, search left half */
    return (sqrt_helper(n, low, mid - 1));
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
    
    /* Use helper function with binary search */
    return (sqrt_helper(n, 1, n));
}

