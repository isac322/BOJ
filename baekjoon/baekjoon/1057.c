#include <stdio.h>

int main() {
	int a, b, i;
	scanf("%d%d%d", &i, &a, &b);
	for (i = 0; a != b; a = (a + 1) / 2, b = (b + 1) / 2, i++);
	printf("%d", i);
}