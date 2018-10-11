#include <stdio.h>

#define swap(x, y) do { typeof(x) temp = x; x = y; y = temp;} while(0)

int Partition(int* A, int p, int r){
	int x = A[r]; //pivot
	int i = p - 1;
	int j = p;
	for(j=p;j<r;j++){
		if(A[j] < x) {
			i += 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[r]);
	return (i + 1);
}

void Quicksort(int* A, int p, int r) {
	int q = 0;
	if(p < r) {
		q = Partition(A, p, r);
		Quicksort(A, p, q-1);
		Quicksort(A, q+1, r);
	}
}

int main(int argc, char** argv){
int A[] = {1, 13, -8, 10, 77, 23, 45, 6, 27, 6, 36, -88};
int len =  (int)(sizeof(A)/sizeof(int));
int i = 0;
int a = 1, b = 2;
swap(a, b);
printf("%d, %d\n", a, b);
#if 1
printf("sizeof A[] : %d\n", (int)(sizeof(A)/sizeof(int)));
printf("Before Quicksort :\n");
for(i=0;i<len;i++){
printf("%d, ", A[i]);
}
printf("\n");
Quicksort(A, 0, len-1);
printf("After quicksort : \n");
for(i=0;i<len;i++){
printf("%d, ", A[i]);
}
printf("\n");
#endif


return 0;
}
