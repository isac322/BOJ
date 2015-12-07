#include <stdio.h>

int main() {
	int arr[] = { 0, 15, 19, 28, 38, 41, 53, 58 };
	int t, n, i, h, cnt, j, k = 0;
	char c, re[11] = "";
	scanf("%d", &n);
	getchar();
	for (k=0; k < n; k++) {
		int min = 6, index = 0;
		for (t = i = 0; i < 6; i++) {
			c = getchar();
			t <<= 1;
			t += c - '0';
		}
		for (i = 0; i < 8; i++) {
			cnt = 0;
			h = t^arr[i];
			for (j = 0; j < 6; j++) if ((h >> j) & 1) cnt++;
			if (min > cnt) {
				index = i;
				min = cnt;
			}
		}
		if (min > 1) {
			printf("%d", k + 1);
			return 0;
		} else {
			re[k] = 65 + index;
		}
	}
	puts(re);
}