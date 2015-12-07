#include <stdio.h>

char mat[12][11];
char ch;
int cnt;
int count[12];

void clear(char column, int row, char to) {
	if (mat[row][column] != ch) return;

	cnt++;
	mat[row][column] = 'r';
	if (column != 0 && mat[row][column - 1] == ch) clear(column - 1, row, to);
	if (column != 9 && mat[row][column + 1] == ch) clear(column + 1, row, to);
	if (row != 0 && mat[row - 1][column] == ch) clear(column, row - 1, to);
	if (row != 11 && mat[row + 1][column] == ch) clear(column, row + 1, to);

	mat[row][column] = to;
	return;
}

int main() {
	int t, i, r, j, k, index;
	char c, tmp;
	while (scanf("%d", &t), t) {
		getchar();
		for (i = 11; i >= 0; i--) gets(mat[i]);
		for (i = 0; i < t; i++) {
			int sum = 120;
			scanf("%c %d", &c, &r);
			getchar();

			cnt = 0;
			ch = mat[r - 1][c - 'a'];
			if (ch) {
				clear(c - 'a', r - 1, -1);

				if (cnt < 3) {
					tmp = ch;
					ch = -1;
					clear(c - 'a', r - 1, tmp);
					continue;
				} else {
					ch = -1;
					clear(c - 'a', r - 1, 0);
				}
				sum -= cnt;

				for (j = 0; j < 10; j++) {
					index = 0;
					for (k = 0; k < 12; k++) {
						count[k] = index;
						if (mat[k][j]) index++;
					}

					for (k = 0; k < 12; k++) {
						if (mat[k][j] && count[k] != k) {
							mat[count[k]][j] = mat[k][j];
							mat[k][j] = 0;
						}
					}
				}

				index = 0;
				for (j = 0; j < 10; j++) {
					count[j] = index;
					if (mat[0][j]) index++;
				}

				for (j = 0; j < 10; j++) {
					if (mat[0][j] && count[j] != j) {
						for (k = 0; k < 12; k++) {
							mat[k][count[j]] = mat[k][j];
							mat[k][j] = 0;
						}
					}
				}
			}
		}

		int q = 0;
		for (j = 0; j < 12; j++) for (k = 0; k < 10; k++) if (mat[j][k]) q++;
		printf("%d\n", q);
	}
}