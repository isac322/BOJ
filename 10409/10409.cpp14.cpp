#include <cstdio>

int main() {
	int n, t, a, s = 0, i = 0;
	scanf("%d%d", &n, &t);
	for (; i < n; i++, s += a) {
		scanf("%d", &a);
		if (a + s > t) break;
	}
	printf("%d", i);
}