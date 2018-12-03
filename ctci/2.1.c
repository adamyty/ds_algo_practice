#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashmap.h"

struct lnode{
	int value;
	struct lnode* prev;
	struct lnode* next;
};

int insert_list(struct lnode** head, int value){

	struct lnode* current;
	struct lnode* newNode;

	newNode = malloc(sizeof(struct lnode));
	if(newNode == NULL){
		printf("%s : Fail to allocate memory for new node\n", __func__);
		return -1;
	}

	newNode->value = value;
	newNode->prev = NULL;
	newNode->next = NULL;

	//insert first node to list
	if(*head == NULL){
		*head = newNode;
		return 0;
	}else{
		current = *head;
		while(current->next!=NULL)
			current = current->next;

		current->next = newNode;
		newNode->prev = current;
		return 0;
	}


	return 0;
}

int display_list(struct lnode* head){

	struct lnode* current;

	if(head == NULL){
		printf("Null list\n");
		return 0;
	}

	current = head;

	while(current != NULL){
		printf("%d -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
	return 0;
}

void free_list(struct lnode* head){

	struct lnode* current;
	struct lnode* pFree;

	if(head == NULL){
		printf("list is NULL\n");
	}
	current = head;
	while(current != NULL){
		pFree = current;
		current = current->next;
		free(pFree);
	}
}

int main(int argc, char**argv){
	hashmap_t* d = NULL;
	struct lnode* head = NULL;
	struct lnode* current = NULL;
	struct lnode* tmp = NULL;
	int i = 0;
	//int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int A[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int A[10] = {10, 111, 13, 127, 10, 35, 126, 137, 218, 9};
	d = alloc_hash_map();
	if(d == NULL){
		printf("d is NULL\n");
		return -1;
	}
	for(i=0;i<10;i++){
		insert_list(&head, A[i]);
	}
	printf("linked list : ");
	display_list(head);
	
	if(head != NULL){
		current = head;
		while(current != NULL){
			//value is first appeared
			if(isKey_in_hash_map(d, current->value) == false){
				hash_map_add_key_value(d, current->value, current->value);
				current = current->next;
			}else{ // value has been appeared before
				if(current->prev !=NULL){
					current->prev->next = current->next;
				}
				if(current->next != NULL)
					current->next->prev = current->prev;

				tmp = current;
				current = current->next;
				free(tmp);
					
			}
		}
	}

	printf("After remove redundant value : ");
	display_list(head);

	free_list(head);
	/*
	for(i=0;i<10;i++){
		hash_map_add_key_value(d, A[i], A[i]);
	}*/
	printf("display hashmap : \n");
	hash_map_display(d);
	free_hash_map(d);
	return 0;
}
