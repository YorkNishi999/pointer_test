#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int* pi = (int*)malloc(sizeof(int));
	//int* pi = NULL;
	
	//int* pi;
	*pi = 9;
	printf("*pi: %p\n", pi);
	printf("*pi: %d\n", *pi);
	free(pi);

	//int* pi2=NULL;
	int* pi2 = (int*)malloc(sizeof(int));
	*pi2 = 8;
	

	printf("*pi2: %p\n", pi2);
	printf("*pi2: %d\n", *pi2);
	free(pi2);


	printf("*pi: %d\n", *pi);
	printf("*pi: %p\n", pi);
	printf("OK\n");
	return 0;
}

