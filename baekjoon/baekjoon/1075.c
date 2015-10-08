#include <stdio.h>

int main() {
	int a, b, i;

	scanf("%d\n%d", &a, &b);
	for (i = a - a % 100; i%b; i++);
	printf("%02d", i % 100);
}