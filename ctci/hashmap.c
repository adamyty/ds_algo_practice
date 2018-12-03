//#include <stdio.h>
//#include <stdlib.h>
#include "hashmap.h"


static int hash(int key){

	return (key % HASHSIZE);
}

hashmap_t* alloc_hash_map(){
	int i = 0;
	printf("alloc hash map\n");
	hashmap_t* hashTbl = malloc(HASHSIZE * sizeof(hashmap_t));
	if(hashTbl == NULL){
		printf("No memroy for hashtable");
		return NULL;
	}

	for(i=0;i<HASHSIZE;i++){
		hashTbl[i].element = NULL;
		//hashTbl[i].hashsize = HASHSIZE;
	}

	return hashTbl;
	
}

void free_hash_map(hashmap_t* hashTbl){
	int i = 0;
	node_t* pBucket = NULL;
	node_t* pFree = NULL;
	for(i=0;i<HASHSIZE;i++){
		//printf("check bucket %d : ", i);
		//if( *(hashTbl+i).element != NULL){ //this code cause compile error
		if(hashTbl[i].element != NULL){
			//printf("not null\n");
			pBucket = hashTbl[i].element;
			while(pBucket != NULL){
				pFree = pBucket;
				pBucket = pBucket->next;
				free(pFree);
			}
		}else{
			//printf("is NULL\n");
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
		//pBucket = node; //stupid error
		hashTbl[hash(key)].element = node;
	} else {
		while(pBucket->next != NULL)
			pBucket = pBucket->next;

		pBucket->next = node;
        pBucket = node;
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

bool isKey_in_hash_map(hashmap_t* hashTbl, int key){

	node_t* pBucket = NULL;

	if(hashTbl[hash(key)].element == NULL)
		return false;

	pBucket = hashTbl[hash(key)].element;
	while(pBucket != NULL){
		if(pBucket->value == key)
			return true;

		pBucket = pBucket->next;
	}

	return false;


}
#if 0

int main(int argc, char**argv){
	hashmap_t* d = NULL;
	int i = 0;
	bool isFound = false;
	//int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int A[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	d = alloc_hash_map();
	if(d == NULL){
		printf("d is NULL\n");
		return -1;
	}
	/*printf("d : 0x%08x\n", d);
	printf("&d : 0x%08x\n", &d);
	printf("======================\n");
	for(i=0;i<HASHSIZE;i++){
		printf("&(d[%d].element) : 0x%08X\n", &(d[i].element));
	}
	printf("======================\n");*/
	
	for(i=0;i<10;i++){
		hash_map_add_key_value(d, A[i], A[i]);
	}
	printf("display hashmap : \n");
	hash_map_display(d);

	isFound = isKey_in_hash_map(d, 1);
	printf("1 is in d? %s\n",isFound?"TRUE":"FALSE");
	isFound = isKey_in_hash_map(d, 10);
    printf("10 is in d? %s\n",isFound?"TRUE":"FALSE");




	free_hash_map(d);
	return 0;
}
#endif
