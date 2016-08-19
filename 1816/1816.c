#include <stdio.h>

int main() {
	char prime[999984] = { 1, 1 };
	int i = 2, j;
	int pos = 0, mat[78498] = { 0 };
	for (; i <= 1000; i++) if (!prime[i]) for (j = (i << 1); j <= 999983; j += i) prime[j] = 1;
	for (i = 2; i < 999984; i++) if (!prime[i]) mat[pos++] = i;
	int n;
	long long t;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &t);
		for (i = 0; i < 78498; i++) {
			if (t%mat[i] == 0) break;
		}
		puts(i == 78498 ? "YES" : "NO");
	}
}