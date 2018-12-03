#include <stdio.h>
#include <stdlib.h>


#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))

struct lnode{
	int val;
	struct lnode* next;
};

int insert_val_to_list(struct lnode** pHead, int val){

	struct lnode* pCur = NULL;
	struct lnode* pNewNode = NULL;

	pNewNode = malloc(sizeof(struct lnode));
	if(pNewNode == NULL){
		printf("Fail to allocate memory for new node\n");
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

int display_list(struct lnode* pHead){

	struct lnode* pCur = NULL;

	if(pHead == NULL){
		printf("List is NULL\n");
		return 0;
	}
	
	pCur = pHead;

	while(pCur != NULL){
		printf("%d -> ", pCur->val);
		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;

}

struct lnode* partition(struct lnode* pHead, int x){
	
	struct lnode* pNewList = NULL;
	struct lnode* pNewListEnd = NULL;
	struct lnode* pTmp = NULL;

	if(pHead == NULL){
		printf("list is null, cannot partition\n");
		return NULL;
	}

	while(pHead != NULL){
		if(pNewList == NULL){
			pNewList = pHead;
			pHead = pHead->next;
			pNewList->next = NULL;
			pNewListEnd = pNewList;			
		}else{
			//pHead->val < x, insert to head
			if(pHead->val < x){
				pTmp = pHead->next;
				pHead->next = pNewList;
				pNewList = pHead;
				pHead = pTmp;
			}else{ //pHead->val >= x, insert to end
				pTmp = pHead->next;
				pNewListEnd->next = pHead;
				pHead->next = NULL;
				pNewListEnd = pHead;
				pHead = pTmp;
			}
		}
	}

	return pNewList;
}

int main(int argc, char** argv){

	int A[] = {3, 5, 8, 5, 10, 2, 1};
	int arrSize = NELEMS(A);
	int i = 0;
	int x = 5;
	struct lnode* pHead = NULL;
	struct lnode* pNewList = NULL;

	for(i=0;i<arrSize;i++){
		insert_val_to_list(&pHead, A[i]);
				
	}

	printf("list : ");
	display_list(pHead);

	pNewList = partition(pHead, x);
	printf("After partition, list :");
	display_list(pNewList);
	return 0;

}
