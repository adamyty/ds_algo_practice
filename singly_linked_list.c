#include <stdio.h>
#include <stdlib.h>

struct nlist {
	struct nlist* next;
	int val;
};

//linked list will have a index to point the last node
// for generalize, first node will be handled in main function (malloc)
int insert(struct nlist* current, int val){
	struct nlist* node = malloc(sizeof(struct nlist));
	if(node == NULL){
		printf("[%s()] Allocate memory fail\n", __func__);
		return -1;
	}
	node->next = NULL;
	node->val = val;

	printf("+current : 0x%08x\n", (unsigned int)current);
	printf("+current->val : %d\n", current->val);
	current->next = node;
	//current = current->next;
	current = node;
    printf("-current : 0x%08x\n", (unsigned int)current);
    printf("-current->val : %d\n", current->val);


	return 0;
}

int display(struct nlist* head){
	struct nlist* current = NULL;
	if(head == NULL){
		printf("linked list is NULL\n");
		return 0;
	}
	current = head;
	printf("linked list :\n");
	while(current != NULL){
		printf("%d -> ", current->val);
		current = current->next;
	}
	printf("NULL\n");
	
	return 0;
}

int main(int argc, char** argv){

	int default_input[] = {-1, 10, 77, -29, 3, 7, 109, 2, -302, 37};
	int default_input_size = sizeof(default_input)/sizeof(int);
	int selection = 0;

	struct nlist* head = NULL;
	struct nlist* current = NULL;

	//Use default input or manually input
	printf("Use 1) default input or 2) manually input? 0) for exit :");
	scanf("%d", &selection);

	//default input, initial linked list
	printf("Use default_input, size : %d\n", default_input_size);
	for(int i=0;i<default_input_size;i++){
		if(head == NULL){
			//head = malloc(sizeof(struct nlist));
			head = (struct nlist*)malloc(sizeof(struct nlist));
			if(head == NULL) {
				printf("[%s()] Allocate memory fail\n", __func__);
				return -1;
			}
			head->next = NULL;
			head->val = default_input[i];
			current = head;
		}
		insert(current, default_input[i]);
	}
	//manually add/delete node to/from linked list
	//display linked list
	display(head);
	return 0;
}
