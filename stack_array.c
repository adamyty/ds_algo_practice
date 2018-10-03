#include <stdio.h>

#define MAXSTACKSIZE 100

void push(int stack[], int* stack_idx, int input) {
	if(*stack_idx == (MAXSTACKSIZE - 1)) {
		printf("stack is full\n");
		return;
	}
	*stack_idx += 1;
	stack[*stack_idx] = input;
}

int pop(int stack[], int* stack_idx) {
	int output = 0;
	if(*stack_idx == -1) {
		printf("stack is empty\n");
		return 0;
	}
	output = stack[*stack_idx];
	*stack_idx -= 1;
	
	return output;
}

void show(int stack[], int stack_idx){
    if(stack_idx == -1) {
        printf("stack is empty\n");
        return;
    }
	printf("[ ");
	for(int i=0;i<= stack_idx;i++){
		printf("%d ", stack[i]);
	}
	printf("]\n");

}

int main(int argc, char** argv) {

int i =0;
int input = 0;
int operation = 0;
int stack[MAXSTACKSIZE];
int stack_idx = -1;
if(argc > 1) {
	for(i=0;i<argc;i++) {
		printf("argv[%d] : %s\n", i, argv[i]);
		printf("*(argv+%d ): %s\n", i, *(argv+i));
	}
}

while(1) {
	printf("select operation 1) push or 2) pop, please input 1 or 2 (input -1 for exit):");
	scanf("%d", &operation);
	if(operation == -1) {
		printf(" exit, stack : ");
		show(stack, stack_idx);
		break;
	}
	switch(operation){
		case 1:
			printf("Input number for push :");
			scanf("%d", &input);
			printf(" push %d into stack\n", input);
			push(stack, &stack_idx, input);
			show(stack, stack_idx);
			break;
		case 2:
			printf(" pop stack\n");
			printf( " get %d\n", pop(stack, &stack_idx));
			show(stack, stack_idx);
			break;
	}
		

}

return 0;
}
