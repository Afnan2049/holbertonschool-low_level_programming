#include "hash_tables.h"

/**
* key_index - Get the index at which a key should be stored in array
* @key: The key to get the index for
* @size: The size of the array of the hash table
*
* Return: The index at which the key/value pair should be stored
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_value;

/* Get the hash value using djb2 algorithm */
hash_value = hash_djb2(key);

/* Return the index by taking modulo with size */
return (hash_value % size);
}
