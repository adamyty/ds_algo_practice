#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int main(int argc, char**argv){
	hashmap_t* d = NULL;
	int i = 0;
	//int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int A[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int A[10] = {10, 111, 13, 127, 4, 35, 126, 137, 218, 9};
	d = alloc_hash_map();
	if(d == NULL){
		printf("d is NULL\n");
		return -1;
	}
	for(i=0;i<10;i++){
		hash_map_add_key_value(d, A[i], A[i]);
	}
	printf("display hashmap : \n");
	hash_map_display(d);

	free_hash_map(d);
	return 0;
}
