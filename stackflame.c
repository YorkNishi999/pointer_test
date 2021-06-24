#include<stdio.h>
#include<stdlib.h>

float average(int *arr, int size) {
	int sum;
	printf("arr(引数): %p\n", &arr);
	printf("size(引数): %p\n", &size);
	printf("sum(局所変数): %p\n", &sum);

	for(int i=0; i<size; i++) {
		sum += arr[i];
	}

	return (sum * 1.0f) / size;
}

int main() {

	int x[] = {1,2,3};
	int* pi = &x[0];
	size_t sizex = sizeof(pi);
	float y = average(x, sizex);
	printf("x[0]: %p\n", &x[0]);
	printf("x[1]: %p\n", &x[1]);
	printf("pi: %p\n", pi);
	printf("pi: %d\n", *pi);
	printf("pi+1: %d\n", *(pi+1));

	return 0;
}
