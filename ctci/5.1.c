#include <stdio.h>

int updateBits(int n, int m, int i, int j){

	int mask = 0;
	int updateNum = 0;
	int k = 0;
	//prepare mask bit i~j
	mask = 1<<(j-i+1);
	//printf("mask : %d\n", mask);
	mask -= 1;
	//printf("mask : %d\n", mask);
	mask <<= i;
	//printf("mask : %d\n", mask);
	mask = ~mask;
	//printf("mask : %d\n", mask);
	//printf("mask :");
	//for(k=16;k;k>>=1)printf(k&mask?"1":"0");
	//printf("\n");
	//clear n bit i~j
	n &= mask;
	//printf("n : %d\n", n);	
	//update m to n bit i~j
	m <<= i;
	//printf("m : %d\n", m);
	updateNum = n|m;
	//printf("updateNum : %d\n", updateNum);
	return updateNum;
}

int highestBit(int m){
	int ret = 0;

	while((m >>= 1) != 0)
		ret += 1;

	return ret;
}

int main(int argc, char** argv){

	int N = 0, M = 0, i = 0, j = 0;
	int updateNum = 0;

	printf("input N: ");
	scanf("%d", &N);
	printf("input M: ");
	scanf("%d", &M);
	printf("input i : ");
	scanf("%d", &i);
	j = i + highestBit(M);
	printf("N : %d M : %d i : %d j : %d\n", N, M, i, j);
	updateNum = updateBits(N, M, i, j);
	printf("After update : %d\n", updateNum);

	return 0;
}
