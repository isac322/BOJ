#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	int c = *(int *)a, d = *(int *)b;
	return c > d ? 1 : c == d ? 0 : -1;
}

int main() {
	int an;
	int a[100000];
	int bn, b;
	int i;

	scanf("%d", &an);
	for (i = 0; i < an; i++) scanf("%d", a + i);

	qsort(a, an, sizeof(int), cmp);

	scanf("%d", &bn);
	for (i = 0; i < bn; i++) {
		scanf("%d", &b);
		if (bsearch(&b, a, an, sizeof(int), cmp)) puts("1");
		else puts("0");
	}
}