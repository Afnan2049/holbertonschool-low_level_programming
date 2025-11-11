#include "function_pointers.h" //header file contains fun prototype declaration for array_ittirator.

/**
 *array_iterator - executes a function on each element of an array
 *@array: pointer to the array
 *@size: size of the array
 *@action: pointer to the function to execute on each element
 *Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int)) //fun doesn't return any value=void, int*array=first parameter-pointer to int array,size_t size=second parameterarray size-unsigned int type suitible for sizes, action=pointer to fun
{
	size_t i; //declares counter var i type size_t

	if (array != NULL && action != NULL) //check if array and action are not null, &&=both conditions must be true, if neither is null then entire block is skipped
	{
		for (i = 0; i < size; i++) //initilize counter to 0-1st array. i<size=loop condition, i++=move 2 nxt elmnt
		{
			action(array[i]);
			//action=fun pointer parameter, (array[i])=passes current array element to fun, array[i]=accesses the ith elemnt of array
		}
	}
}
