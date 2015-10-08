#include <stdio.h>

int main() {
	int a[100][100] = { 0 }, b[100][100] = { 0 };
	int n, m, o, tmp;
	int i, j, k;
	scanf("%d %d\n", &n, &m);
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
	scanf("%d %d", &m, &o);
	for (i = 0; i < m; i++) for (j = 0; j < o; j++) scanf("%d", &b[i][j]);
	for (i = 0; i < n; i++) {
		for (j = 0; j < o; j++) {
			tmp = 0;
			for (k = 0; k < m; k++) tmp += a[i][k] * b[k][j];
			printf("%d ", tmp);
		}
		puts("");
	}
}