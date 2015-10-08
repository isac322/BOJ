#include <stdio.h>

char count[201] = { 0 };

int main() {
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		count[t + 100]++;

	}
	scanf("%d", &n);
	printf("%d\n", count[n + 100]);
}