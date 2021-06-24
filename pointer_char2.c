#include<stdio.h>
#include<stdlib.h>

char* blanks(int number) {
	char* spaces = (char*)malloc(number+1);

	for (int i=0; i<number; i++) 
		spaces[i] = 's';
	
	spaces[number] = '\0';

	return spaces; // return pointer
}

int main(int argc, char** argv) {

	char* c = argv[1];

	printf("%s\n", c);

	int a = atoi(c);
	char* tmp = blanks(a);

	printf("%d\n", a);
	printf("%s\n", tmp);

	return 0;

}


