#include <stdio.h>
#include <stdlib.h>

int main() {
	int **num = NULL;
	int m, n, tmp;
	int i, j;

	scanf("%d %d", &m, &n);

	num = (int **)calloc(m, sizeof(int));
	for (i = 0; i < m; i++) {
		num[i] = (int*)calloc(n, sizeof(int));
		for (j = 0; j < n; j++) scanf("%d", &num[i][j]);
	}

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &tmp);
			printf("%d ", num[i][j] += tmp);
		}
		puts("");
	}
}