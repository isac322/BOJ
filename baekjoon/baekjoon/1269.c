#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

int main() {
	int a[200000], b[200000];
	int n, m, t, i, ai = 0, bi = 0, cnt = 0, c, d;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	for (i = 0; i < m; i++) scanf("%d", b + i);
	qsort(a, n, sizeof(int), cmp);
	qsort(b, m, sizeof(int), cmp);
	while (ai < n && bi < m) {
		c = a[ai];
		d = b[bi];
		if (c == d) {
			cnt++;
			ai++;
			bi++;
		} else if (c < d) ai++;
		else bi++;
	}
	printf("%d", n + m - (cnt << 1));
}