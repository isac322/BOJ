#include <stdio.h>

char matrix[65][65] = { 0 };

void compress(int r, int c, int n) {
	char first = matrix[r][c];

	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (matrix[i][j] != first) {
				putchar('(');
				compress(r, c, n >> 1);
				compress(r, c + (n >> 1), n >> 1);
				compress(r + (n >> 1), c, n >> 1);
				compress(r + (n >> 1), c + (n >> 1), n >> 1);
				putchar(')');
				return;
			}
		}
	}

	putchar(first);
}

int main() {
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) gets(matrix[i]);

	compress(0, 0, n);
}