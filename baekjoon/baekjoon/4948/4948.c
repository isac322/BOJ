#include <stdio.h>

int main() {
	char prime[246913] = { 1, 1, 0 };
	int i = 2, j;
	for (; i < 498; i++) if (!prime[i]) for (j = (i << 1); j < 246913; j += i) prime[j] = 1;
	int n, cnt, m;
	while (scanf("%d", &n) && n) {
		cnt = 0;
		m = n << 1;
		for (i = n + 1; i <= m; i++) if (!prime[i]) cnt++;
		printf("%d\n", cnt);
	}
}