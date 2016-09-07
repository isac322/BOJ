#include <cstdio>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int a, b, c;
	scanf("%d%d", &a, &b);
	c = gcd(a, b);
	printf("%d\n%d", c, a * b / c);
}