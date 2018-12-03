#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HASHSIZE 10
typedef struct node{
	int key;
	int value;
	struct node* next;
} node_t;
typedef struct hashmap{
    node_t* element;
} hashmap_t;

hashmap_t* alloc_hash_map();
void free_hash_map(hashmap_t* hashTbl);
int hash_map_add_key_value(hashmap_t* hashTbl, int key, int value);
int hash_map_display(hashmap_t* hashTbl);
bool isKey_in_hash_map(hashmap_t* hashTbl, int key);
#endif
