#include <stdio.h>
#include <memory.h>

bool mat[50][50] = { 0 };
int n, m, k, i, j, y, x, t, cnt;

void re(int i, int j) {
	mat[i][j] = 0;
	if (i && mat[i - 1][j]) re(i - 1, j);
	if (i != n - 1 && mat[i + 1][j]) re(i + 1, j);
	if (j && mat[i][j - 1]) re(i, j - 1);
	if (j != m - 1 && mat[i][j + 1]) re(i, j + 1);
	return;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(mat, 0, 2500);
		scanf("%d %d %d", &m, &n, &k);
		for (cnt = i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			mat[y][x] = 1;
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (mat[i][j]) {
					cnt++;
					re(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}