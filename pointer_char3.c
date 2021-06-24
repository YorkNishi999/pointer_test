#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int (*fptrOperation)(const char*, const char*);


void sort(char* array[], int size, fptrOperation operation){
	int swap = 1;
	while(swap) {
		swap = 0;
		for(int i = 0; i<size-1; i++) {
			printf("%s\n", array[i]); 
			printf("%s\n", array[i+1]); 
			printf("%d\n", operation(array[i], array[i+1])); 
			if(operation(array[i], array[i+1]) > 0) {
				swap = 1;
				char* tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
			}
		}
	}
}

void displayNames(char* names[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%s	", names[i]);
	}
	printf("\n");
}

int compare(const char* s1, const char* s2) {
	return strcmp(s1, s2);
}

int main () {
	
	char* names[] = {"alice","Ted","Carol","Aob","Alice"};

	sort(names, 5, compare);
	displayNames(names, 5);

}
