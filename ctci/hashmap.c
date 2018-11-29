#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"


static int hash(int key){

	return (key % HASHSIZE);
}

hashmap_t* alloc_hash_map(){
	printf("alloc hash map\n");
	hashmap_t* hashTbl = malloc(HASHSIZE * sizeof(hashmap_t));
	if(hashTbl == NULL){
		printf("No memroy for hashtable");
		return NULL;
	}

	return hashTbl;
	
}

void free_hash_map(hashmap_t* hashTbl){
	int i = 0;
	node_t* pBucket = NULL;
	node_t* pFree = NULL;
	for(i=0;i<HASHSIZE;i++){
		printf("check %d bucket\n", i);
		//if( *(hashTbl+i).element != NULL){ //this code cause compile error
		if(hashTbl[i].element != NULL){
			printf("not null\n");
			pBucket = hashTbl[i].element;
			while(pBucket != NULL){
				pFree = pBucket;
				pBucket = pBucket->next;
				free(pFree);
			}
		}
	}
	free(hashTbl);
	
}

int hash_map_add_key_value(hashmap_t* hashTbl, int key, int value){

	node_t* node = NULL;
	node_t* pBucket;
	node = malloc(sizeof(node_t));

	if(node == NULL){
		printf("No memory for node\n");
		return -1;
	}
	node->key = key;
	node->value = value;
	node->next = NULL;

	pBucket = hashTbl[hash(key)].element;
	if(pBucket == NULL){
		pBucket = node;
	} else {
		while(pBucket->next != NULL)
			pBucket = pBucket->next;

		pBucket->next = node;
	}

	return 0;
}

int hash_map_display(hashmap_t* hashTbl){

	int i = 0;
	node_t* pBucket = NULL;
	
	if(hashTbl == NULL){
		printf("hashTbl is NULL\n");
		return -1;	
	}
	
	for(i=0;i<HASHSIZE;i++){
		printf("bucket %d : ", i);
		pBucket = hashTbl[i].element;
		if(pBucket == NULL){
			printf("NULL\n");
		}else{
			while(pBucket != NULL){
				printf("%d -> ", pBucket->value);
				pBucket = pBucket->next;
			}
			printf("NULL\n");
		}
	}

	return 0;

}
