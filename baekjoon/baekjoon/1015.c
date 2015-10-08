#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i, n;
}DATA;

int cmp(const void *a, const void *b) {
	return ((DATA *) a)->n - ((DATA *) b)->n;
}

int cmp2(const void *a, const void *b) {
	return ((DATA *) a)->i - ((DATA *) b)->i;
}

int main() {
	DATA d[50] = { 0 };
	int n, i = 0;
	scanf("%d", &n);
	for (; i < n; i++) {
		scanf("%d", &d[i].n);
		d[i].i = i;
	}
	qsort(d, n, sizeof(DATA), cmp);
	for (i = 0; i < n; i++) d[i].n = i;
	qsort(d, n, sizeof(DATA), cmp2);
	for (i = 0; i < n; i++) printf("%d ", d[i].n);
}