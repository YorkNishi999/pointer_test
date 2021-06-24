#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

int main() {

	// 文字列配列で宣言、定義
	char c[] = "AAAAA";
	printf("%s\n", c); // cは配列型で定義しているが、ポインタと同じ働き

	// 文字列ポインタで宣言、定義
	char* cp = (char*)malloc(strlen("BBBBB")+1);
	strcpy(cp, "BBBBB");
	printf("%s\n", cp);

	// 文字列定数のアドレスを、文字列ポインタに直接代入
	char* cp2 = "CCCCC";
	printf("%s\n", cp2);


	//char* tabHeader = "Sound";
	//*tabHeader = 'L';

}
