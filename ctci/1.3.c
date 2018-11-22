#include <stdio.h>
#include <string.h>

void URLify(char* A){
	int spaceCnt = 0;
	int i = 0, j = 0, URLstrLen = 0;
	for(i=0;i<strlen(A);i++){
		if(A[i] ==' ' )
			spaceCnt += 1;
	}
	URLstrLen = strlen(A) + 3 * spaceCnt;
	j = URLstrLen;
	printf("%d %d\n", strlen(A), j);
	for(i=strlen(A);i>=0;i--){
		if(A[i] == ' '){
			printf("i : %d j : %d\n", i, j);
			strncpy(A[j-2], "%20", 3);
			j -= 3;
		} else {
			printf("i : %d j : %d\n", i, j);
			A[j] = A[i];
			j--;
		}
	}
}

int main(int argc, char** argv){
	char A[256];
	printf("input string A : ");
	scanf("%s", &A);
	printf("After URLify, string A : %s\n", A);
	return 0;
}

