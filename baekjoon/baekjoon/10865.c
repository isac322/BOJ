#include <stdio.h>

int main() {
	unsigned int cnt[100000] = { 0 };
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;

		cnt[a]++;
		cnt[b]++;
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", cnt[i]);
	}
}