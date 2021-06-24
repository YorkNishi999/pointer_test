#include<cstdio>

int main() {

	char x[] =  {"A", "B", "C"};
	//char* titles[3] = {"AAA", "BBB", "CCC"};
	int* titles[3] = x;
	int** best[3];

	best[0] = &titles[0];
	//best[1] = &titles[2];
	//best[2] = &titles[1];

	printf("titles[0] is %p\n", titles[0]);
	//printf("*titles[0] is %s\n", *titles[0]);
	//printf("&titles[0] is %s\n", &titles[0]);

	printf("best[0] is %p\n", best[0]);
	printf("*best[0] is %p\n", *best[0]);
	printf("*best[0] is %s\n", *best[0]);
	//printf("*best[0] is %s\n", *best[0]);
	//printf("**best[0] is %d\n", **best[0]);
	//printf("&best[0] is %p\n", &best[0]);

	return 0;
}

