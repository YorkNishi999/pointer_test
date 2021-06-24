#include<cstdio>

int main() {
	int num = 5;
	const int limit = 100;
	int *pi;
	const int *pci;

	pi = &num;
	pci = &limit;

	printf("num		-	Address: %p, Value: %d\n", &num, num);
	printf("limit		-	Address: %p, Value: %d\n", &limit, limit);
	printf("pi		-	Address: %p, Value: %p\n", &pi, pi);
	printf("pci		-	Address: %p, Value: %p\n", &pci, pci);

	printf("pci		- 間接value: %d\n", *pci);

	pci = &num;
	*pci = 19;

	printf("num		-	Address: %p, Value: %d\n", &num, num);
	printf("limit		-	Address: %p, Value: %d\n", &limit, limit);
	printf("pi		-	Address: %p, Value: %p\n", &pi, pi);
	printf("pci		-	Address: %p, Value: %p\n", &pci, pci);

	printf("pci		- 間接value: %d\n", *pci);

}

