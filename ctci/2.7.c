#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int insert_node_to_tail_list(struct lnode** pHead, struct lnode* pNode){
	
	struct lnode* pCur = NULL;

	if(pNode == NULL){
		printf("ERROR! should not insert NULL to list\n");
		return -1;
	}

	if(*pHead == NULL){
		*pHead = pNode;
		return 0;
	}

	pCur = *pHead;
	while(pCur->next != NULL)
		pCur = pCur->next;

	pCur->next = pNode;

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

struct lnode* locate_intersection_node_by_value_list(struct lnode* pHead, int value){

	while(pHead != NULL){
		if(pHead->val == value)
			return pHead;

		pHead = pHead->next;
	}

	return NULL;

}

int length_list(struct lnode* pHead){
	
	int length = 0;

	if(pHead == NULL)
		return 0;

	while(pHead != NULL){
		length += 1;
		pHead = pHead->next;
	}

	return length;
}

struct lnode* find_intersection_node_list(struct lnode* pHeadA, struct lnode* pHeadB){

	if(pHeadA == NULL || pHeadB == NULL)
		return NULL;

	while(pHeadA != NULL && pHeadB != NULL){
		if(pHeadA == pHeadB)
			return pHeadA;

		pHeadA = pHeadA->next;
		pHeadB = pHeadB->next;
	}

	return NULL;

}


int main(int argc, char** argv){
	
	int A[] = { 3, 1, 5, 9, 7, 2, 1};
	int B[] = { 4, 6};
	int intNodeValA = 7;
	int arrSzA = NELEMS(A);
	int arrSzB = NELEMS(B);
	int lenListA = 0;
	int lenListB = 0;
	int i = 0;
	int lenDiff = 0;

	struct lnode* pHeadA = NULL;
	struct lnode* pHeadB = NULL;
	struct lnode* pIntNodeQuestion = NULL;
	struct lnode* pIntNodeAnswer = NULL;
	struct lnode* pHeadTruncate = NULL;
	struct lnode* pTmp = NULL;
	//init list A
	for(i=0;i<arrSzA;i++){
		insert_value_to_list(&pHeadA, A[i]);
	}

	//init list B
	for(i=0;i<arrSzB;i++){
        insert_value_to_list(&pHeadB, B[i]);
    }

	pIntNodeQuestion = locate_intersection_node_by_value_list(pHeadA, intNodeValA);

	insert_node_to_tail_list(&pHeadB, pIntNodeQuestion);

	display_list(pHeadA);
	display_list(pHeadB);
	
	lenListA = length_list(pHeadA);
	lenListB = length_list(pHeadB);

	lenDiff = lenListA - lenListB;

	//list A B has same length
	if(lenDiff == 0){
		pIntNodeAnswer = find_intersection_node_list(pHeadA, pHeadB);
	} else{
		//list B is longger, truncate it
		if(lenDiff < 0 ){
			pTmp = pHeadB;
			lenDiff = abs(lenDiff);
			while(lenDiff != 0){
				pTmp = pTmp->next;
				lenDiff -= 1;
			}

			pHeadTruncate = pTmp;
			pIntNodeAnswer = find_intersection_node_list(pHeadA, pHeadTruncate);
		}
		// list A is longer, truncate it
		if(lenDiff > 0){
			pTmp = pHeadA;
			while(lenDiff !=0 ){
				pTmp = pTmp->next;
				lenDiff -= 1;
			}

			pHeadTruncate = pTmp;
			pIntNodeAnswer = find_intersection_node_list(pHeadTruncate, pHeadB);
		}
	}

	if(pIntNodeAnswer == NULL){
		printf("two list have no intersection\n");
	}else{
		printf("two list have intersection, value is : %d\n", pIntNodeAnswer->val);
	}
	
	free_list(pHeadA);
	free_list(pHeadB);

	return 0;
}
