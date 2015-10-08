#include <stdio.h>

int main() {
	char map[13][13] = { "" };
	int r, c, cnt;
	scanf("%d %d\n", &r, &c);
	for (int i = 1; i <= r; i++) gets(map[i] + 1);

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cnt = 0;
			if (map[i][j] == 'X') {
				if (map[i][j - 1] == '.' || map[i][j - 1] == 0) cnt++;
				if (map[i + 1][j] == '.' || map[i + 1][j] == 0) cnt++;
				if (map[i][j + 1] == '.' || map[i][j + 1] == 0) cnt++;
				if (map[i - 1][j] == '.' || map[i - 1][j] == 0) cnt++;
				if (cnt > 2) map[i][j] = 'x';
			}
		}
	}

	int w = r, a = c, s = 1, d = 1;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == 'x') map[i][j] = '.';
			else if (map[i][j] == 'X') {
				if (i > s) s = i;
				if (i < w) w = i;
				if (j > d) d = j;
				if (j < a) a = j;
			}
		}
	}
	for (int i = w; i <= s; i++) {
		for (int j = a; j <= d; j++) putchar(map[i][j]);
		puts("");
	}
}