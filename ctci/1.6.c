#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRMAXSIZE 256

void strCompress(char* A, char* B){

	int strLenA = 0;
	int i = 0;
	
	strLenA = (int)strlen(A);
	char charNow = '\0';
	int charCnt = 0;
	int arrayIdx = 0;
	int cntSprintf = 0;

	for(i=0;i<strLenA;i++){
		if(A[i] != charNow){
			//first char
			if(charNow == '\0'){
				B[arrayIdx] = A[i];
				arrayIdx += 1;
				charCnt += 1;
				charNow = A[i];
			} else { // normal case
				//printf("+arrayIdx : %d\n", arrayIdx);
				//wrong method, you should using sprintf
				//B[arrayIdx] = (char)charCnt;
				cntSprintf = sprintf(&B[arrayIdx], "%d", charCnt);
				arrayIdx += cntSprintf;
				cntSprintf = 0;
				charCnt = 0;
				B[arrayIdx] = A[i];
				arrayIdx += 1;
				charCnt += 1;
				charNow = A[i];
				//printf("-arrayIdx : %d\n", arrayIdx);
			}
		} else {
			charCnt += 1;
		}

	}
	printf("string A : %s\n", A);
	printf("string B : %s\n", B);
	if(strlen(A) <= strlen(B)){
		strncpy(B, A, STRMAXSIZE);
	}

}

int main(int argc, char** argv){

	char A[STRMAXSIZE] = "";
	char B[STRMAXSIZE] = "";
	printf("input string : ");
	scanf("%s", A);
	strCompress(A, B);
	printf("After string compression : %s\n", B);
	return 0;
}
