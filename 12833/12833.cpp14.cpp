#include <cstdio>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (c & 1) a ^= b;
	printf("%d", a);
}