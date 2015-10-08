#include <stdio.h>

int main() {
	int a, b, c, d, e;
	scanf("%d %d %d", &a, &b, &c);
	d = (a + b) % c;
	e = (a*b) % c;
	printf("%d\n%d\n%d\n%d", d, d, e, e);
}