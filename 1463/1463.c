#include <stdio.h>

int cnt[1000001] = { 0, 0, 1, 1 }, n;

int main() {
	scanf("%d", &n);
	for (int m = 4; m <= n; m++) {
		int tw = m & 1, thr = m % 3;
		if (!tw && !thr) {
			int a = cnt[m >> 1];
			int b = cnt[m / 3];
			int c = cnt[m - 1];
			int d = a > b ? b : a;
			cnt[m] = (c > d ? d : c) + 1;
		} else if (!tw) {
			int a = cnt[m >> 1];
			int b = cnt[m - 1];
			cnt[m] = (a > b ? b : a) + 1;
		} else if (!thr) {
			int a = cnt[m / 3];
			int b = cnt[m - 1];
			cnt[m] = (a > b ? b : a) + 1;
		} else cnt[m] = cnt[m - 1] + 1;
	}
	printf("%d", cnt[n]);
}