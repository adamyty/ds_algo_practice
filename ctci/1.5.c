#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool func_isOneAway(char* A, char* B){

	int cntTblA[128] = {0};
	int cntTblB[128] = {0};
	int cntDiff = 0;
	int strLenDiff = 0;
	int type = 0;
	int minStrLen = 0;
	int i = 0, j = 0;

	//strlen(A-B) : -1 insert 1 remove 0 replace, assign to cntDiff and check for each element
	// simplify, insert & remove can appear one diff, replace can appear 2 diff
	strLenDiff = (int)((strlen(A) - strlen(B)));
	printf("strlenDiff : %d\n", strLenDiff);

	if(abs(strLenDiff) > 1 )
		return false;

	printf("strlen A : %d\n", (int)strlen(A));
	printf("strlen B : %d\n", (int)strlen(B));
	minStrLen = (strlen(A) < strlen(B)) ? (int)strlen(A) : (int)strlen(B);
	printf("minStrLen : %d\n", minStrLen);
	//case replace : 1 insert : 2 remove : 3
	if(strLenDiff == 0)
		type = 1;
    if(strLenDiff == -1)
        type = 2;
    if(strLenDiff == 1)
        type = 3;

	cntDiff = 1;


	//check diff
	for(i=0;i<=minStrLen;i++, j++){
		if(A[i] != B[j]){
			switch (type){
				case 1:
					break;
				case 2:
					j++;
					if(A[i] != B[j])
						return false;
					break;
				case 3:
					i++;
					if(A[i] != B[j])
						return false;
					break;
				default:
					printf("wrong type\n");
					break;
			}
			cntDiff -= 1;

		}
	}

	if(cntDiff != 0)
		return false;

	return true;
	

}

int main(int argc, char** argv){

	char A[256] = "";
	char B[256] = "";
	bool isOneAway = false;

	/* input two string with %[^n]s will cause problem. I guess is '\n' cause issue
	printf("input string A :");
	scanf("%[^\n]s", A);
	printf("input string B : ");
	scanf("%[^\n]s", B);
	*/
	printf("input string A :");
	fgets(A, 256, stdin);
	printf("input string B : ");
	fgets(B, 256, stdin);

	isOneAway = func_isOneAway(A, B);

	printf("are string A & B one away? %s\n", isOneAway?"TRUE":"FALSE");

}
