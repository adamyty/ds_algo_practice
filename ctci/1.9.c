#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSubstring(char* A, char* B){

	char* tmp = NULL;
	tmp = malloc(2*(int)strlen(A)*sizeof(char));
	strncpy(tmp, A, (int)strlen(A));
	strncpy((tmp + (int)strlen(A)), A, (int)strlen(A));
	if(strstr(tmp, B) != NULL)
		return true;

	return false;
}

int main(int argc, char** argv){

	char A[256] = "";
	char B[256] = "";

	printf("input origin string : ");
	scanf("%s", A);
	printf("input check string : ");
	scanf("%s", B);
	printf("is Substring ? %s\n", isSubstring(A, B)?"TRUE":"FALSE");


	return 0;
}
