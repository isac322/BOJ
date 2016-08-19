#include <stdio.h>

int main() {
	char mat[50][51] = { 0 };
	int i, j, k, n, m, max = 0;

	scanf("%d %d\n", &n, &m);
	for (i = 0; i < n; i++) gets(mat[i]);
	for (i = 0; i < n - 1; i++) for (j = 0; j < m - 1; j++) for (k = j + 1; k < m; k++) if (mat[i][j] == mat[i][k] && k - j > max && i + k - j < n) if (mat[i][j] == mat[i + k - j][j] && mat[i][j] == mat[i + k - j][k]) max = k - j;
	printf("%d", (max + 1)*(max + 1));
}