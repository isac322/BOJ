#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int a[3], tot;

	scanf("%d %d %d", a, a + 1, a + 2);
	qsort(a, 3, sizeof(int), cmp);

	if (a[0] == a[1] && a[1] == a[2] && a[0] == a[2]) tot = 10000 + *a * 1000;
	else if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2]) tot = a[2] * 100;
	else tot = 1000 + a[1] * 100;

	printf("%d", tot);
}