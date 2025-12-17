#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
* hash_table_set - Add or update an element in a hash table
* @ht: The hash table to add/update the key/value to
* @key: The key (cannot be an empty string)
* @value: The value associated with the key (must be duplicated, can be empty)
* Return: 1 if succeeded, 0 otherwise
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int idx;
hash_node_t *node, *tmp;
char *val_copy;

if (!ht || !key || !*key || !value)
return (0);
val_copy = strdup(value);
if (!val_copy)
return (0);
idx = key_index((unsigned char *)key, ht->size);
tmp = ht->array[idx];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = val_copy;
return (1);
}
tmp = tmp->next;
}
node = malloc(sizeof(hash_node_t));
if (!node)
return (free(val_copy), 0);
node->key = strdup(key);
if (!node->key)
return (free(val_copy), free(node), 0);
node->value = val_copy;
node->next = ht->array[idx];
ht->array[idx] = node;
return (1);
}
