/*
	quick sort and binary search
*/
#include <stdio.h>

#define swap(x, y) do { typeof(x) tmp = x; x = y; y = tmp;} while(0)

int partition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	int j = p;
	for(j=p;j<r;j++){
		if(A[j] < x) {
			i += 1;
			swap(A[i], A[j]);
		}
	}
	//printf(" %d : ",i);
	/*swap(A[++i], A[r]);
	printf(" %d \n: ",i);
	return i;*/
	swap(A[i+1], A[r]);
	//printf("%d\n", i+1);
	return i+1;
}

void quicksort(int* A, int p, int r) {
	int q = 0;
	if(p<r) {
		q = partition(A, p, r);
		//printf("q : %d\n", q);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int bs(int* A, int p, int r, int target){
	int index = -1;
	int root = -1;
	if(p <= r) {
		root = (p + r)/2;
		if(target == A[root])
			return root;
		if(target < A[root])
			return bs(A, p, root - 1, target);
		if(target > A[root])
			return bs(A, root + 1, r, target);
	}

	return -1;
}

int main(int argc, char** argv) {

	int A[] = {-1, 3, 77, 20, -19, 123, 5786, -23, 0, 57, -29, -1, 3};
	int len = sizeof(A)/sizeof(int);
	int i = 0;
	int target = -1;
	printf("Before sort (%d): ", len);
	for(i=0;i<len;i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
	printf("After sort : ");
	quicksort(A, 0, len-1);
	for(i=0;i<len;i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	printf("input search target : ");
	scanf("%d", &target);
	printf("\nsearch target : %d\n", target);
	i = bs(A, 0, len-1, target);
	if(i == -1){
		printf("Target is not in Array\n");
	} else {
		printf("Found target :%d in A[%d] : %d\n", target, i, A[i]);
	}

	return 0;
}
