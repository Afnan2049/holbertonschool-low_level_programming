#include "hash_tables.h"
#include <string.h>

/**
* hash_table_get - Retrieve a value associated with a key
* @ht: The hash table to look into
* @key: The key to look for
*
* Return: The value associated with the element, or NULL if key not found
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int index;
hash_node_t *tmp;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

/* calculate the index for this key */
index = key_index((const unsigned char *)key, ht->size);

/* traverse the linked list at this index */
tmp = ht->array[index];
while (tmp != NULL)
{
if (strcmp(tmp->key, key) == 0)
return (tmp->value);
tmp = tmp->next;
}

/* key not found */
return (NULL);
}
