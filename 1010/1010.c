#include <stdio.h>
#include <memory.h>

int main() {
	int n, r, tmp;
	unsigned long long result;
	int i, j, t;
	char ch[30] = { 0 };
	scanf("%d", &t);
	while (t--) {
		result = 1;

		scanf("%d %d", &r, &n);
		memset(ch, 1, r);
		for (i = 1; i <= r; i++) {
			tmp = n;
			for (j = 2; j <= r; j++) {
				if (!(tmp % j) && ch[j - 1]) {
					tmp /= j;
					ch[j - 1] = 0;
				}
			}
			result *= tmp;
			n--;
		}
		for (; r > 1; r--) if (ch[r - 1]) result /= r;
		printf("%llu\n", result);
	}
}