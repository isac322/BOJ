#include <cstdio>

int f[35] = { 0,0,0,1 };

int main() {
	for (int i = 4; i < 35; i++) f[i] = f[i - 1] + f[i - 2];
	int d, k;
	scanf("%d %d", &d, &k);
	for (int i = 1;; i++) {
		for (int j = 1;; j++) {
			const int q = f[d] * i + f[d + 1] * j;
			if (q > k) break;
			else if (q == k) {
				printf("%d\n%d", i, j);
				return 0;
			}
		}
	}
}