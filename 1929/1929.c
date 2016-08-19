#include <stdio.h>
#include <math.h>

int main() {
	int m, n, t, i, j;
	char prime[1000001] = { 1, 1 };
	scanf("%d %d", &m, &n);
	t = sqrt(n);
	for (i = 2; i <= t; i++) if (!prime[i]) for (j = (i << 1); j <= n; j += i) prime[j] = 1;
	for (i = m; i <= n; i++) if (!prime[i]) printf("%d\n", i);
}