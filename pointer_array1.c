#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int vector[3] = {1,2,3};
	int* pv = vector;

	printf("%d\n", pv[1]);
	printf("%d\n", *(pv));

}
