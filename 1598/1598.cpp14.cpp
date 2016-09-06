#include <cstdio>
#include <algorithm>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	a--, b--;
	int c1 = a >> 2, c2 = b >> 2, r1 = a & 3, r2 = b & 3;
	printf("%d", abs(c1 - c2) + abs(r1 - r2));
}