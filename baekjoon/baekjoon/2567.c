#include <stdio.h>
#include <memory.h>

int main() {
	int xMax = 0, yMax = 0;
	int n, cnt = 0;
	int x, y;
	int i, j;
	char mat[104][104] = { 0 };

	scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &x, &y);
		if ((x += 2) > xMax) xMax = x;
		if ((y += 2) > yMax) yMax = y;

		for (i = y; i - y < 10; i++) {
			for (j = x; j - x < 10; j++) {
				mat[i][j] = 1;
			}
		}
	}

	for (i = 1; i < yMax + 11; i++) {
		for (j = 1; j < xMax + 11; j++) {
			if (!mat[i][j]) cnt += mat[i + 1][j] + mat[i - 1][j] + mat[i][j - 1] + mat[i][j + 1];
		}
	}
	printf("%d", cnt);
}