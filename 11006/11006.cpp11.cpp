#include <cstdio>

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		printf("%d %d\n", m * 2 - n, n - m);
	}
}