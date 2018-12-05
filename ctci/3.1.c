#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NELEMS(x) (sizeof(x)/sizeof((x[0])))
int stackFloor[3] = {-1};
int stackCeiling[3] = {-1};
int stackTop[3] = {-1};

int display_array(int* pArray, int arrSz){
	
	int i = 0;

	if(pArray == NULL){
		printf("[%s] array is NULL\n", __func__);
		return -1;
	}

	if(arrSz < 0 ){
		printf("[%s] arrSz < 0 : %d\n", __func__, arrSz);
		return -1;
	}

	for(i=0;i<arrSz;i++){
		printf("| %d ", *(pArray + i));
	}
	printf("|\n");
	
	return 0;
}

int resize_array(int** pArray, int elemDiff, int* pArrSz){

	int* pNew = NULL;
	int* pFree = NULL;
	int newArrSz = *pArrSz + elemDiff;
#if 0
	pNew = realloc(*pArray, newArrSz*sizeof(int));

	if(pNew == NULL){
		printf("[%s] fail to resize array\n", __func__);
		return -1;
	}else{
		*pArray = pNew;
		*pArrSz = newArrSz;
	}
#endif

	pNew = malloc(sizeof(int)*elemDiff);
	if(pNew == NULL){
		printf("[%s] fail to resize array\n", __func__);
        return -1;
	}else{
		memset(pNew, 0, newArrSz);
		memcpy(pNew, *pArray, *pArrSz);
		free(*pArray);
		*pArray = pNew;
	}

	return 0;
}
int push_stack(int** pArray, int* arrSz, int stackIdx, int val){

	int ret = 0;
	int i = 0;
	int tmp = 0;
	int* pStack = NULL;
	
	if(stackIdx < 0 || 2 < stackIdx){
		printf("[%s] ERROR! stack idx should be 0~2\n", __func__);
		return -1;
	}
	
	if(*pArray == NULL){
		printf("[%s] ERROR! array is NULL\n", __func__);
		return -1;
	}
	//pStack = *pArray;
	printf("push val : %d to stack[%d]\n", val, stackIdx);
	//check if stackTop[stackIdx] reach its ceiling
	//if does, resize array
	if(stackTop[stackIdx] == stackCeiling[stackIdx]){
		ret = resize_array(pArray, 1, arrSz);
		if(ret != 0){
			printf("[%s] ERROR! fail to increase array size, haven't push new value to stack[%d]\n", __func__, stackIdx);
			return -1;
		}
		pStack = *pArray;
		//shift other stack's elements
		for(i=2;i>stackIdx;i--){
			//if stack[i] is not empty
			if(stackTop[i] != stackFloor[i] -1){
				tmp = stackTop[i];
				while(tmp != stackFloor[i]){
					pStack[tmp+1] = pStack[tmp];
					tmp--;
				}
			}
			//adjust related idx
			stackFloor[i] += 1;
			stackCeiling[i] += 1;
			stackTop[i] += 1;
		}

		//push value to stack
		stackTop[stackIdx] += 1;
		pStack[stackTop[stackIdx]] = val;
		stackCeiling[stackIdx] += 1;
	}else{
		//stack has space, push value
		pStack = *pArray;
		stackTop[stackIdx] += 1;
		pStack[stackTop[stackIdx]] = val;
	}

	printf("[%s] stackTop[%d] : %d\n", __func__, stackIdx, stackTop[stackIdx]);
	printf("[%s] pStack[stackTop[%d]] : %d\n", __func__, stackIdx, pStack[stackTop[stackIdx]]);
	printf("[%s] addr : 0x%08X\n", __func__, (pStack + stackTop[stackIdx]));
	return 0;
}

int init_stack(int arrSz){

	int i =0;
	int remainArrSz = arrSz;
	int stackSz = 0;

	if(arrSz < 3){
		printf("[%s] ERROR! array size < 3\n", __func__);
		return -1;
	}

	stackSz = arrSz/3;

	for(i=0;i<3;i++){
		stackFloor[i] = i*stackSz;
		stackCeiling[i] = (i + 1)*stackSz - 1;
		stackTop[i] = stackFloor[i] -1;
		remainArrSz -= stackSz;
	}

	if(remainArrSz > 0)
		stackCeiling[2] += remainArrSz;

	return 0;

}

int display_stack(int* pStack){

	int i = 0, j = 0;

	for(i=0;i<3;i++){
		printf("stack[%d]\n", i);
		printf("top : %d\n", stackTop[i]);
		printf("floor : %d\n", stackFloor[i]);
		printf("ceiling : %d\n", stackCeiling[i]);
		for(j=stackFloor[i];j<=stackTop[i];j++){
			printf("|%d",pStack[j]);
		}
		printf("(TOP)|\n");
	}

	return 0;
}
int main(int argc, char** argv){

	//int A[] = {0, 1, 2};
#if 0
	int A[3][4] = {
					{0, 1, 2, 3},
					{100, 101, 102, 103},
					{200, 201, 202, 203}
	};
#endif
	int A[3][3] = {
					{0, 1, 2},
					{100, 101, 102},
					{200, 201, 202}
	};

	int* pArray = NULL;
	//int arrSz = NELEMS(A0);
	int arrSz = 3;
	int i = 0, j = 0;

	pArray = malloc(arrSz * sizeof(int));

	init_stack(arrSz);
#if 0
	for(i=0;i<arrSz;i++){
		*(pArray + i) = A[i];
	}
	printf("origin array size : %d\n", arrSz);
	display_array(pArray, arrSz);

	resize_array(&pArray, 5, &arrSz);
	printf("after resize array, array size : %d\n", arrSz);
	display_array(pArray, arrSz);
#endif
	printf("after init stack\n");
	display_stack(pArray);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			push_stack(&pArray, &arrSz, i, A[i][j]);
			printf("%d %d arrSz : %d\n",i , j, arrSz);
			printf("element : %d\n", *(pArray + i*3 + j));
			printf("addr : 0x%08X\n", (pArray + i*3 + j));
		}
	}
	printf("\nafter push value to stack\n");
	display_stack(pArray);
	free(pArray);
	return 0;
}
