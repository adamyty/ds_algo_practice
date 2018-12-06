#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int** pSetOfStacks = NULL;

int main(int argc, char** argv){

	int A[3][3] = {
		{0, 1, 2},
		{100, 101, 102},
		{201, 202, 203}
	};

	int i = 0, j = 0;
	int* B;

	//allocate pSetOfStacks, there are 3 stacks
	pSetOfStacks = malloc(3*sizeof(int*));
	printf("pSetOfStacks : 0x%08lx\n", pSetOfStacks);

	//init all stacks
	/*for(i=0;i<3;i++){
		(*pSetOfStacks + i) = NULL;
	}*/

	for(i=0;i<3;i++){
		B = (*pSetOfStacks + i);
		B = malloc(3*sizeof(int));
		//(*pSetOfStacks + i) = malloc(3*sizeof(int));
	}

	for(i=0;i<3;i++){
		B = (*pSetOfStacks + i);
		for(j=0;j<3;j++){
			printf("0x%08lX, %d\n", (intptr_t)(B + j), A[i][j]);
			*(B + j*sizeof(int)) = A[i][j];
		}
	}

	for(i=0;i<3;i++){
		printf("stack[%d] : ", i);
        B = (*pSetOfStacks + i);
        for(j=0;j<3;j++){
            printf("%d ",*(B + j*sizeof(int)));
        }
		printf("\n");
    }

	//free
	for(i=0;i<3;i++){
		free(*pSetOfStacks + i);
	}

	free(pSetOfStacks);

	return 0;
}
