#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* hash_table_set - Add or update an element in a hash table
* @ht: The hash table to add/update the key/value to
* @key: The key (cannot be an empty string)
* @value: The value associated with the key (must be duplicated, can be empty)
*
* Return: 1 if succeeded, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *new_node, *temp;
unsigned long int index;
char *value_copy;

/* Check for invalid inputs */
if (ht == NULL || key == NULL || *key == '\0')
return (0);

/* Duplicate the value string */
value_copy = strdup(value);
if (value_copy == NULL)
return (0);

/* Get the index for this key */
index = key_index((const unsigned char *)key, ht->size);

/* Check if key already exists in the chain */
temp = ht->array[index];
while (temp != NULL)
{
if (strcmp(temp->key, key) == 0)
{
/* Key exists - update the value */
free(temp->value);
temp->value = value_copy;
return (1);
}
temp = temp->next;
}

/* Key doesn't exist - create new node */
new_node = malloc(sizeof(hash_node_t));
if (new_node == NULL)
{
free(value_copy);
return (0);
}

/* Duplicate the key string */
new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(value_copy);
free(new_node);
return (0);
}

/* Set up the new node */
new_node->value = value_copy;

/* Insert at beginning of chain (handles collisions) */
new_node->next = ht->array[index];
ht->array[index] = new_node;

return (1);
}
