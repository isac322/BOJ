#include <stdio.h>

int main() {
	int a = 1, b;
	scanf("%d", &b);
	a = a << b;
	printf("%d", ++a*a);
}