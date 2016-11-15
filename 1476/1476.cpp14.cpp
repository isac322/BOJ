#include <cstdio>

int main() {
	int a, b, c, n;
	scanf("%d%d%d", &a, &b, &c);
	for (n = b - 1; n % 15 != a - 1 || n % 19 != c - 1; n += 28);
	printf("%d", n + 1);
}