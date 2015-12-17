#include <cstdio>

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		printf("Case %d: %d\n", i, a + b);
	}
}