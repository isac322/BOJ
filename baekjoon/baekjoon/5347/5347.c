#include <stdio.h>

long long gcd(long long a, long long b) {
	if (!(a%b)) return b;
	return gcd(b, a%b);
}

int main() {
	int num;
	long long re, a, b;

	scanf("%d", &num);
	while (num--) {
		scanf("%lld %lld", &a, &b);
		re = a*b / gcd(a, b);
		printf("%lld\n", re);
	}
}