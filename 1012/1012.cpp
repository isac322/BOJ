#include <stdio.h>
#include <memory.h>

bool mat[50][50] = { 0 };
int n, m, k;

void re(int i, int j) {
	mat[i][j] = 0;
	if (i && mat[i - 1][j]) re(i - 1, j);
	if (i != n - 1 && mat[i + 1][j]) re(i + 1, j);
	if (j && mat[i][j - 1]) re(i, j - 1);
	if (j != m - 1 && mat[i][j + 1]) re(i, j + 1);
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(mat, 0, 2500);
		int i = 0, j, y, x, cnt = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (; i < k; i++) {
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