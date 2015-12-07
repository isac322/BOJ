#include <stdio.h>
#include <stdlib.h>

int cmp(const void *c, const void *d) {
	double a = *(double *) c, b = *(double *) d;
	if (a == b) return 0;
	else if (a > b) return -1;
	else return 1;
}

int main() {
	int n, m, k, in;
	double score[100] = { 0 }, t, sum = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d %lf", &in, &t);
			if (t > score[in - 1]) score[in - 1] = t;
		}
	}
	qsort(score, n, sizeof(double), cmp);
	for (int i = 0; i < k; i++) sum += score[i];
	printf("%0.1lf", sum);
}