#include <stdio.h>

void insertion_sort(int* a, int len){

	int i, j, temp;
	for(i=0;i<len;i++) {
		temp = a[i];
		for(j=i;j>0 && a[j-1] > temp;j--)
			a[j] = a[j-1];
		a[j] = temp;
	}

}

int main(int argc, char** argv) {

	int a[10] = {1, 10, 13, 10, 55, 4, 9, 17, 45, 67};
	int i = 0;
	insertion_sort(a, 10);
	for(i=0;i<10;i++)
		printf("%d\n", a[i]);

}
