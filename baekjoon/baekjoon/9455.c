#include <stdio.h>

int main() {
	int i, j, t, m, n, cnt;

	scanf("%d", &t);
	while (t--) {
		int mat[100][100], min[100] = { 0 };
		scanf("%d %d", &m, &n);

		cnt = 0;
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", *(mat + i) + j);
				if (!mat[i][j]) min[j] = i;
			}
		}

		for (i = 0; i < n; i++) {
			for (j = min[i]; j >= 0; j--) {
				if (mat[j][i]) {
					cnt += min[i] - j;
					mat[min[i]][i] = 1;
					mat[j][i] = 0;
					j = min[i]--;
				}
			}
		}
		printf("%d\n", cnt);
	}
}