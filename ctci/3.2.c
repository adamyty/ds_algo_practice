#include <stdio.h>
#include <stdbool.h>

#define NELEMS(x) = (sizeof(x)/sizeof((x)[0]))
#define STACKSIZE 128

int stack[STACKSIZE] = {0};
int minStack[STACKSIZE] = {0};
int stackTop = -1;
int minStackTop = -1;
int minElem = 0;

int push(int val){
	
	if(stackTop == (STACKSIZE-1)){
		printf("stack is full\n");
		return -1;
	}
	//check min element
	if(stackTop == -1)
		minElem = val;
	if(val <= minElem){
		minElem = val;
		minStackTop += 1;
		minStack[minStackTop] = val;
	}

	//push val to stack
	stackTop += 1;
	stack[stackTop] = val;

	return 0;
}

int pop(void){
	
	int val = -1;
	if(stackTop == -1){
		printf("stack is empty\n");
		return val;
	}
	//pop stack
	val = stack[stackTop];
	stackTop -= 1;

	//check if min element is poped out
	if(val == minElem){
		minStack[minStackTop] = 0;
		minStackTop -= 1;
		minElem = minStack[minStackTop];
	}

	return val;

}

int display_stack(void){

	int i = 0;

	if(stackTop == -1){
		printf("stack is empty\n");
		return -1;
	}
	for(i=0;i<=stackTop;i++){
		printf("|%d", stack[i]);
	}
	printf("(TOP)|\n");

	return 0;
}

int main(int argc, char** argv){

	int val = 0;
	int choose = 0;
	bool isExit = false;

	while(!isExit){
		printf("1)push 2)pop 3)display 4)min 0)exit : ");
		scanf("%d", &choose);

		switch(choose){
			case 1:
				printf("input push value : ");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				val = pop();
				printf("pop value : %d\n", val);
				break;
			case 3: 
				printf("display stack :\n");
				display_stack();
			case 4:
				printf("min element in stack : %d\n", minElem);
				break;
			case 0:
			default:
				printf("exit!!\n");
				isExit = true;
				break;
		}
	}

	return 0;

}
