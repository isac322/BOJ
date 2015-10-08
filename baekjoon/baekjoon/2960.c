#include <stdio.h>

int main() {
	char prime[1001] = { 1, 1 };
	int n, k, i = 2, j;
	scanf("%d %d", &n, &k);
	for (; i <= n; i++) {
		if (!prime[i]) {
			for (j = i; j <= n; j += i) {
				if (!prime[j]) {
					prime[j] = 1;
					k--;
					if (!k) goto hell;
				}
			}
		}
	}
hell:	printf("%d\n", j);
}