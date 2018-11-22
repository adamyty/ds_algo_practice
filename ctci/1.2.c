#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//return true or false. In linux kernel, it has own define
bool isPermutation(char* A, char* B){
	int cnt[256] = {0};
	int i = 0;
	if(strlen(A) != strlen(B))
		return false;
	for(i=0;i<strlen(A);i++){
		cnt[(int)(A[i])] += 1;
		printf("stringA : %c : %d\n", A[i], cnt[(int)(A[i])]);
	}
	
	for(i=0;i<strlen(B);i++){
		cnt[(int)(B[i])] -= 1;
		printf("string B :%c : %d\n", B[i], cnt[(int)(B[i])]);
		if(cnt[(int)(B[i])] < 0)
			return false;
	}
	return true;
}

int main(int argc, char** argv){
	char A[256];
	char B[256];
	printf("input string A : ");
	scanf("%s", &A);
	printf("input string B : ");
	scanf("%s", &B);
	printf("string A : %s\n", A);
	printf("string B : %s\n", B);
	printf("two string is permutation? %s\n", isPermutation(A, B) ? "TRUE" : "FALSE");

	return 0;
}
