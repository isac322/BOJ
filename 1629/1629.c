#include <stdio.h>

unsigned long long a, b, c;
unsigned long long f(unsigned long long n, unsigned long long x) {
	if (x == 0) return 1;
	if (x & 1) {
		unsigned long long t = f(n, x - 1) % c;
		return n*t%c;
	} else {
		unsigned long long h = f(n, x >> 1) % c;
		return h*h%c;
	}
}

int main() {
	scanf("%llu %llu %llu", &a, &b, &c);
	printf("%llu", f(a, b));
}