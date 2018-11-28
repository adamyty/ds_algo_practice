#include <stdio.h>
#include <stdlib.h>

#define ARRAYSIZE 5

void display(int A[ARRAYSIZE][ARRAYSIZE]){
	int i = 0, j = 0;
	
	for(i=0;i<ARRAYSIZE;i++){
		for(j=0;j<ARRAYSIZE;j++){
			if((j%ARRAYSIZE) == 0)
				printf("{");
			printf("%3d,",A[i][j]);
			if((j%ARRAYSIZE) == (ARRAYSIZE - 1))
				printf("}\n");
		}
	}
}
//left rotate
void rotation(int A[ARRAYSIZE][ARRAYSIZE]){
	int tmp;
	int x = 0, y = 0;

	for(x=0;x<ARRAYSIZE/2;x++){
		for(y=x;y<ARRAYSIZE-1-x;y++){
			tmp = A[x][y];//backup up
			A[x][y] = A[y][ARRAYSIZE-1-x];//right to up
			A[y][ARRAYSIZE-1-x] = A[ARRAYSIZE-1-x][ARRAYSIZE-1-y];//bottom to right
			A[ARRAYSIZE-1-x][ARRAYSIZE-1-y] = A[ARRAYSIZE-1-y][x];//left to bottom
			A[ARRAYSIZE-1-y][x] = tmp; //up to left
		}
	}

}

int main(int argc, char** argv){

	int A[ARRAYSIZE][ARRAYSIZE] = {0};
	int i = 0, j = 0, num = 0;

	for(i=0;i<ARRAYSIZE;i++){
		for(j=0;j<ARRAYSIZE;j++){
			A[i][j] = num;
			num += 1;
		}
	}
	display(A);
	rotation(A);
	printf("After left 90 degree rotation :\n");
	display(A);
	return 0;
}
