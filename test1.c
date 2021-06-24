#include<cstdio>

int main() {
	
	int x = 100;
	long dx = 100.75945948;
	printf("変数xが指す整数 %d\n", x);
	int* z = &x;
	printf("ポインタ変数z %p\n", z);
	printf("ポインタ変数zの参照値 %d\n", *z);
	z = z + 1;
	printf("ポインタ変数z %p\n", z);
	printf("ポインタ変数zの参照値 %d\n", *z);
	long* dz = &dx;
	*z = 20;
	int s = sizeof(z);
	int ds = sizeof(dz);
	//y = &x;
	//printf("%p\n", &x);
	printf("ポインタ変数z %p\n", z);
	printf("ポインタzの大きさ %d\n", s);
	printf("ポインタlzの大きさ %d\n", ds);
	printf("変数xのアドレス %p\n", &x);
	printf("ポインタ変数zのアドレス %p\n", &z);
	printf("ポインタ変数zが指す整数 %d\n", *z);
	printf("変数xが指す整数 %d\n", x);
	//printf("%p\n", &y);
	// y += 1;
	//printf("%d\n", y);
	//printf("%p\n", &y);
	//free();
	return 0;
}

