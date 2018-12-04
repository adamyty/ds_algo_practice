#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))
#define MAXSTACKSIZE 128

int stack[MAXSTACKSIZE] = {0};
int top = -1;
struct lnode{
	int val;
	struct lnode* next;
};

int insert_value_to_list(struct lnode** pHead, int val){
	
	struct lnode* pCur = NULL;
	struct lnode* pNewNode = NULL;

	pNewNode = malloc(sizeof(struct lnode));
	if(pNewNode == NULL){
		printf("fail to allocate memory for new node\n");
		return -1;
	}

	pNewNode->val = val;
	pNewNode->next = NULL;

	if(*pHead == NULL){
		*pHead = pNewNode;
		return 0;
	}

	pCur = *pHead;
	while(pCur->next != NULL)
		pCur = pCur->next;

	pCur->next = pNewNode;

	return 0;
}

int free_list(struct lnode* pHead){

	struct lnode* pFree = NULL;

	if(pHead == NULL)
		return 0;

	while(pHead != NULL){
		pFree = pHead;
		pHead = pHead->next;
		pFree->next = NULL;
		free(pFree);
		pFree = NULL; //This is unecessary in here?
		pFree = pHead;
	}
	
	return 0;
}

int display_list(struct lnode* pHead){

	if(pHead == NULL){
		printf("list is NULL\n");
		return 0;
	}

	while(pHead != NULL){
		printf("%d -> ", pHead->val);
		pHead = pHead->next;
	}
	printf("NULL\n");
	
	return 0;

}

bool isPalindrome_list(struct lnode* pHead){

	struct lnode* pFast = NULL;
	struct lnode* pSlow = NULL;

	if(pHead == NULL)
		return true;

	pFast = pHead;
	pSlow = pHead;

	//fast traversal 2 step, slow traversal 1 step
	while(pFast != NULL && pFast->next != NULL){
		//push to stack
		top +=1;
		stack[top] = pSlow->val;

		pSlow = pSlow->next;
		pFast = pFast->next->next;
	}
	
	//odd nodes, ignore middle one
	if(pFast != NULL)
		pSlow = pSlow->next;

	while(pSlow != NULL){
		//pop from stack
		if(stack[top] != pSlow->val)
			return false;

		top -= 1;
		pSlow = pSlow->next;
	}

	return true;
}

int main(int argc, char** argv){
	
	//int A[] = {0, 1, 2, 3, 2, 1, 0};
	//int A[] = { 0, 1, 2, 3, 3, 2, 1, 0};
	int A[] = { 1, 2};
	int arrSzA = NELEMS(A);
	int i = 0;
	bool isListPalindrome = false;

	struct lnode* pHeadA = NULL;

	//init list A
	for(i=0;i<arrSzA;i++){
		insert_value_to_list(&pHeadA, A[i]);
	}

	display_list(pHeadA);

	isListPalindrome = isPalindrome_list(pHeadA);

	printf("Is list palindrome? %s\n", isListPalindrome?"TRUE":"FALSE"); 

	return 0;
}
