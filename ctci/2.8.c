#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NELEMS(x) (sizeof(x)/sizeof((x)[0]))

struct lnode{
	char val;
	struct lnode* next;
};

int insert_value_to_list(struct lnode** pHead, char val){

	struct lnode* pCur = NULL;
	struct lnode* pNewNode = NULL;
	
	pNewNode = malloc(sizeof(struct lnode));
	
	if(pNewNode == NULL){
		printf("[%s] fail to allocate memory for new node\n", __func__);
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
	//double free issue when free loop list
	while(pHead != NULL){
		printf("free %c\n", pHead->val);
		pFree = pHead;
		pHead = pHead->next;
		pFree->next = NULL;
		free(pFree);
		pFree = NULL;
	}

	return 0;
}

int release_loop_list(struct lnode* pHead, struct lnode* pLoopStartNode){

	bool isStepInLoop = false;
	struct lnode* pPrev = NULL;

	if(pHead == NULL || pLoopStartNode == NULL){
		printf("[%s] pHead or pLoopStartNode is NULL\n", __func__);
		return -1;
	}

	while(pHead != NULL){
		
		if(pHead == pLoopStartNode){
			if(isStepInLoop){
				// in loop and meet loop start node again
				pPrev->next = NULL;
				return 0;
			}else{
				// first step in loop
				isStepInLoop = true;
			}
		}

		pPrev = pHead;
		pHead = pHead->next;
	}

	return 0;
}

struct lnode* locate_loop_start_node(struct lnode* pHead, char val){

	struct lnode* pCur = NULL;

	if(pHead == NULL)
		return NULL;

	pCur = pHead;
	while(pCur != NULL){
		if(pCur->val == val)
			return pCur;

		pCur = pCur->next;
	}

	return NULL;
}

int insert_node_to_list(struct lnode** pHead, struct lnode* pNode){

	struct lnode* pCur = NULL;
	
	if(pNode == NULL){
		printf("[%s] should not insert NULL node to list\n", __func__);
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

struct lnode* find_loop_start_node_list(struct lnode* pHead){
	
	struct lnode* pSlow = NULL;
	struct lnode* pFast = NULL;
	struct lnode* pCollide = NULL;

	//corner case : NULL list 
	if(pHead == NULL)
		return NULL;

	//be aware start and end rule
	pSlow = pHead;
	pFast = pHead;
	while(pFast != NULL && pFast->next != NULL){
		pSlow = pSlow->next;
		pFast = pFast->next->next;

		if(pSlow == pFast){
			pCollide = pSlow;
			break;
		}
	}

	if(pCollide != NULL){
		while(1){
			if(pHead == pCollide){
				return pCollide;
			}
			
			pHead = pHead->next;
			pCollide = pCollide->next;
		}
	}

	return NULL;
}

int main(int argc, char** argv){

	char A[] = {'A', 'B', 'C', 'D', 'E'};
	int arrSzA = NELEMS(A);
	int i = 0;
	char loopStartNodeVal = 'C';

	struct lnode* pHeadA = NULL;
	struct lnode* pLoopStartNodeQuestion = NULL;
	struct lnode* pLoopStartNodeAnswer = NULL;

	for(i=0;i<arrSzA;i++){
		insert_value_to_list(&pHeadA, A[i]);
	}

	pLoopStartNodeQuestion = locate_loop_start_node(pHeadA, loopStartNodeVal);
	insert_node_to_list(&pHeadA, pLoopStartNodeQuestion);
	
	pLoopStartNodeAnswer = find_loop_start_node_list(pHeadA);

	if(pLoopStartNodeAnswer == NULL){
		printf("list has no loop\n");
	}else{
		printf("list has loop, loop start node is %c\n", pLoopStartNodeAnswer->val);
	}

	release_loop_list(pHeadA, pLoopStartNodeAnswer);

	free_list(pHeadA);

	return 0;

}
