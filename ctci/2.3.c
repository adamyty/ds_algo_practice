#include <stdio.h>
#include <stdlib.h>

struct lnode{
	char val;
	struct lnode* next;
};

int insert_list(struct lnode** head, char val){

	struct lnode* current;
	struct lnode* newNode;
	
	newNode = malloc(sizeof(struct lnode));
	if(newNode == NULL){
		printf("Fail to allocate memory for new node\n");
		return -1;
	}
	
	newNode->val = val;
	newNode->next = NULL;
	//First node insert to list
	if(*head == NULL){
		*head = newNode;
		return 0;
	}

	current = *head;
	while(current->next != NULL)
		current = current->next;

	current->next = newNode;

	return 0;
}

int free_list(struct lnode* head){
	struct lnode* current = NULL;
	struct lnode* pFree = NULL;

	if(head == NULL)
		return 0;

	current = head;
	while(current != NULL){
		pFree = current;
		current = current->next;
		free(pFree);
	}
	
	return 0;
		
}

int display_list(struct lnode* head){

	struct lnode* current = NULL;

	if(head == NULL){
		printf("list is NULL\n");
		return 0;
	}

	current = head;
	while(current != NULL){
		printf("%c -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");

	return 0;
}

int main(int argc, char** argv){
	char A[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int arrSize = sizeof(A)/sizeof(char);
	int i = 0;
	char targetVal = 'd';
	struct lnode* head = NULL;
	struct lnode* current = NULL;
	struct lnode* target = NULL;

	for(i=0;i<arrSize;i++){
		insert_list(&head, A[i]);
	}
	printf("linked list : ");
	display_list(head);
	current = head;
	while(current != NULL){
		if(current->val == targetVal){
			target = current;
			break;
		}
		current = current->next;
	}

	printf("target val : %c\n", target->val);

	current = target;
	while(current->next != NULL){
		current->val = current->next->val;
		current = current->next;
	}
	free(current);
	current = NULL;
	
	printf("After remove target node : ");
	display_list(head);

	free_list(head);
	
	return 0;
}

