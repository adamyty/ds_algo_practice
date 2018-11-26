#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//a ~ z : 97 ~ 122 A ~ Z : 65 ~ 90
void lowercase(char* a){

	if( (65<= (int)(*a)) && ( (int)(*a) <= 90 ) )
		*a += 32;

}

bool isPalindromePerm(char* A) {

	int cntTbl[128] = {0};
	int oddCnt = 0;
	int i = 0;

	//check str len, if strlen is odd, there can be one char appear odd.
	if(((int)strlen(A) % 2) == 1){
		oddCnt = -1;
	}
	for(i=0;i<(int)strlen(A);i++){
		lowercase(&A[i]);
		cntTbl[(int)(A[i])] += 1;
	}
	for(i=0;i<128;i++){
		if((cntTbl[i] % 2) == 1)
			oddCnt += 1;

		if(oddCnt > 0)
			return false;
	}

	return true;
	
}

int main(int argc, char** argv){

	char A[256] = "";
	int i = 0;
	bool isPalindrome = false;

	printf("input string :");
	scanf("%[^\n]s", A);
	printf("strlen %d\n",(int)strlen(A));
	isPalindrome = isPalindromePerm(A);
	for(i=0;i<(int)strlen(A);i++){
		//lowercase(&A[i]);
		printf("%c : %d\n", A[i], A[i]);
	}

	printf("\nstring \"%s\" is palindrome permutation? %s\n", A, isPalindrome ? "TRUE":"FALSE");
	return 0;
}
