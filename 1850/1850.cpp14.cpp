#include <cstdio>

int main() {
	unsigned long long a, b, c;
	scanf("%llu %llu", &a, &b);
	while (b) {
		c = a%b;
		a = b;
		b = c;
	}
	while (a--) putchar('1');
}