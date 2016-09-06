#include <cstdio>

int main() {
	int n, s = 0, a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		a = a*i - s;
		s += a;
		printf("%d ", a);
	}
}