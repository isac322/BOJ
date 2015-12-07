#include <stdio.h>

int main() {
	bool a[1000001] = { false };
	int i, j, n, t;

	for (i = 2; i < 1001; i++) {
		if (a[i]) continue;
		for (j = i<<1; j < 1000001; j += i) a[j] = true;
	}

	while (scanf("%d", &n) && n) {
		t = n / 2;
		for (i = 1; i < t; i++) {
			if (!a[i + 1] && !a[n - i - 1]) {
				printf("%d = %d + %d\n", n, i + 1, n - i - 1);
				break;
			}
		}
		if (i == t) puts("Goldbach's conjecture is wrong.");
	}
}