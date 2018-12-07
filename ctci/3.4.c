#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACKSZ 128

//stack[0] : new stack stack[1] : old stac
int stack[2][STACKSZ] = {0};
int stackTop[2] = {-1, -1};

bool isStackFull(int stackIdx){
	
	if(stackTop[stackIdx] == (STACKSZ - 1))
		return true;

	return false;
}

bool isStackEmpty(int stackIdx){

	if(stackTop[stackIdx] == -1)
		return true;

	return false;
}

int push(int stackIdx, int val){

	if(stackIdx < 0 || 1 < stackIdx){
		printf("Invalid stackIdx : %d\n", stackIdx);
		return -1;
	}
	if(isStackFull(stackIdx)){
		printf("stack[%d] is full\n", stackIdx);
		return -1;
	}

	stackTop[stackIdx] += 1;
	stack[stackIdx][stackTop[stackIdx]] = val;

	return 0;
}

int pop(int stackIdx){

	int retVal = 0;

	if(isStackEmpty(stackIdx)){
		printf("stack[%d] is empty\n", stackIdx);
		return -1;
	}

	retVal = stack[stackIdx][stackTop[stackIdx]];
	stackTop[stackIdx] -= 1;

	return retVal;
}

int enqueue(int val){

	int tmp = 0;

	//if stack[0] is full and stack[1] is not empty, return error
	if(isStackFull(0) && !isStackEmpty(1)){
		printf("enqueue : Queue is full\n");
		return -1;
	}

	//if stack[0] if full, dump stack[0] to stack[1]
	if(isStackFull(0)){
		while(stackTop[0] > -1){
			tmp = pop(0);
			push(1, tmp);
		}
	}

	//enqueue to stack[0]
	push(0, val);

	return 0;
}

int dequeue(void){

	int retVal = 0;

	if(isStackEmpty(0) && isStackEmpty(1)){
		printf("dequeue : Queue is empty\n");
		return -1;
	}
	if(isStackEmpty(1)){
		while(stackTop[0] > -1){
			push(1, pop(0));
		}
	}
	retVal = pop(1);

	return retVal;
}

int display(void){

	int i = 0;

	if(isStackEmpty(0) && isStackEmpty(1)){
		printf("Queue is empty\n");
		return -1;
	}
	printf("Queue : ");
	if(!isStackEmpty(1)){
		for(i=stackTop[1];i>-1;i--){
			printf("%d ", stack[1][i]);
		}
	}
	if(!isStackEmpty(0)){
		for(i=0;i<=stackTop[0];i++){
			printf("%d ", stack[0][i]);
		}
	}
	printf("(end)\n");

	return 0;
}
int main(int argc, char** argv){

	int choose = -1;
	int val = 0;
	bool isExit = false;

	while(!isExit){
		printf("1)enqueue 2)dequeue 3)display 0)exit :");
	    scanf("%d", &choose);
		switch(choose){

			case 1:
				printf("input enqueue val : ");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2:
				printf("dequeue val : %d\n", dequeue());
				break;
			case 3:
				display();
				break;
			case 0:
			default:
				isExit = true;
				break;
		}
	}

	return 0;
}
