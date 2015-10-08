#include <stdio.h>

int main() {
	unsigned long long n;
	for (scanf("%llu", &n); n; scanf("%llu", &n)) {
		printf("%llu\n", n*(n + 1)*(n + 2) / 6);
	}
}