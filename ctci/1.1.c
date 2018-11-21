/*
 * 1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
 */

#include <stdio.h>
#include <stdlib.h>

struct nlist {
	struct nlist* next;
	char val;
};

// char size 1 byte
#define MAXHASHSIZE 128

struct nlist* hashTbl[MAXHASHSIZE];

int insert(struct nlist** head, char val){

	struct nlist* node = malloc(sizeof(struct nlist));
	struct nlist* tmp = NULL;

	if(node == NULL){
		printf("%s allocate memory fail\n", __func__);
		return -1;
	}

	node->next = NULL;
	node->val = val;

	if(*head == NULL){
		*head = node;
		return 0;
	}

	tmp = *head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	tmp->next = node;

	return 0;
}

int display(struct nlist* head){

	if(head == NULL){
		printf("NULL list\n");
		return 0;
	}
	while(head != NULL){
		printf("%c -> ", head->val);
		head = head->next;
	}
	printf("null\n");
	return 0;
}


int main(int argc, char** argv) {
	char inputStrArray[] = "adam";
	int strLen = 0;
	int i = 0;

	strLen = sizeof(inputStrArray) / sizeof(char);

	for(i=0;i<strLen;i++){
		printf("%c : %d\n", inputStrArray[i], (int)inputStrArray[i]);
		insert(&hashTbl[(int)inputStrArray[i]],  inputStrArray[i]);
	}

	for(i=0;i<MAXHASHSIZE;i++){
		if(hashTbl[i] != NULL){
			printf("%d : ", i);
			display(hashTbl[i]);
		}
	}

	return 0;
}
