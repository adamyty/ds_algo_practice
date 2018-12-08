#include <stdio.h>

int flipBit(int a){
	
	int prevLen = 0, curLen = 0;
	int maxLen = 1;

	if(~a == 0)
		return (8*sizeof(int));

	while(a!=0){
		if((a&1) == 1){
			curLen += 1;
		}
		if((a&1) == 0){
			//consecutive 0 occured
			if((a&2) == 0){
				prevLen = 0;
				curLen = 0;
			}else{
			// only one 0 occured
				prevLen = curLen;
				curLen = 0;
			}
			//observe the above code, you can find out that a&2 only affect prevLen
			/*
		 	 * prevLen = ((a&2)==0)? 0 : curLen;
			 * curLen = 0;	
 			 */	 
		}
		maxLen = (prevLen + curLen + 1) > maxLen ? (prevLen + curLen + 1) : maxLen;
		a >>= 1;
	}

	return maxLen;
}

int main(int argc, char** argv){

	int a = 0, maxLength = 0;;
	printf("input an integer : ");
	scanf("%d", &a);
	maxLength = flipBit(a);
	
	printf("a after flip a bit, you can get longest 1's sequence length : %d\n", maxLength);
	
	return 0;
	
}
