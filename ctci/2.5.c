#include <stdio.h>
#include <stdlib.h>

#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))

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
	if(pHead == NULL){
		//printf("list is NULL\n");
		return 0;
	}

	pFree = pHead;
	while(pHead != NULL){
		pHead = pHead->next;
		free(pFree);
		pFree = NULL;
		pFree = pHead;
	}

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

int reverse_list(struct lnode** pHead){
	
	struct lnode* pCur = NULL;
	struct lnode* pPrev = NULL;
	struct lnode* pNext = NULL;

	if(*pHead == NULL){
		printf("list is NULL, cannot reverse\n");
		return 0;
	}

	pCur = *pHead;

	while(pCur != NULL){
		pNext = pCur->next;
		pCur->next = pPrev;
		pPrev = pCur;
		pCur = pNext;
	}

	*pHead = pPrev;

	return 0 ;
}

struct lnode* add_two_list(struct lnode* pHeadA, struct lnode* pHeadB){
	int carry = 0;
	int val = 0;
	struct lnode* pResult = NULL;

	if(pHeadA == NULL && pHeadB == NULL)
		return NULL;

	if(pHeadA == NULL)
		return pHeadB;

	if(pHeadB == NULL)
		return pHeadA;

	while(pHeadA != NULL || pHeadB != NULL){
		if(pHeadA != NULL){
			val += pHeadA->val;
			pHeadA = pHeadA->next;
		}
		if(pHeadB != NULL){
			val += pHeadB->val;
			pHeadB = pHeadB->next;
		}

		val += carry;
		carry = val / 10;
		val = val % 10;
		printf("val : %d carry : %d\n", val, carry);
		
		insert_value_to_list(&pResult, val);
		val = 0;

	}

	return pResult;
}


int main(int argc, char** argv){

	int A[] = {1, 2, 3, 4};
	int B[] = {5, 6, 7};
	int arrSzA = NELEMS(A);
	int arrSzB = NELEMS(B);
	int i = 0;
	struct lnode* pHeadA = NULL;
	struct lnode* pHeadB = NULL;
	struct lnode* pResult = NULL;

	//init linked list A
	for(i=0;i<arrSzA;i++){
		insert_value_to_list(&pHeadA, A[i]);	
	}
    //init linked list B
	#if 1
	for(i=0;i<arrSzB;i++){
		insert_value_to_list(&pHeadB, B[i]);
	}
	#endif

	printf("list A : ");
	display_list(pHeadA);
	printf("list B : ");
	display_list(pHeadB);

	printf("After reverse :\n");
	reverse_list(&pHeadA);
	reverse_list(&pHeadB);
    printf("list A : ");
    display_list(pHeadA);
    printf("list B : ");
    display_list(pHeadB);

	pResult = add_two_list(pHeadA, pHeadB);

	printf("\nAfter add two list, result:\n");
	display_list(pResult);

	free_list(pHeadA);
	free_list(pHeadB);
	free_list(pResult);



	return 0;
}
