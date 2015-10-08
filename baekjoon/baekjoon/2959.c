#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int a[4];
	scanf("%d%d%d%d", a, a + 1, a + 2, a + 3);
	qsort(a, 4, sizeof(int), cmp);
	printf("%d", a[0] * a[2]);
}