#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include <stdio.h>
#include <stdlib.h>

typedef struct hashmap{
    int key;
    int value;
} hashmap_t;


void alloc_hash_map();
#endif
