#include <stdio.h>

int main() {
	int pri[100000];
	char prime[1299710] = { 1, 1, 0 };
	int pos = 0;
	int i = 2, j;
	for (; i < 1142; i++) if (!prime[i]) for (j = (i << 1); j < 1299710; j += i) prime[j] = 1;
	for (i = 2; i < 1299710; i++) if (!prime[i]) pri[pos++] = i;
	int n, t, l, r, m;
	scanf("%d", &n);
l:	while (n--) {
		scanf("%d", &t);
		l = 0;
		r = 99999;
		while (l <= r) {
			m = (l + r) >> 1;
			if (t == pri[m]) {
				puts("0");
				goto l;
			} else if (t > pri[m])l = m + 1;
			else r = m - 1;
		}
		while (t > pri[m]) m++;
		while (t < pri[m]) m--;
		printf("%d\n", pri[m + 1] - pri[m]);
	}
}