#include <cstdio>
#include <cmath>

long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}

long long ch(long long a, long long b) {
	if (a == 1) return b;
	long long g, i;
	i = ceill(b / (double) a);
	a = a*i - b;
	b *= i;
	g = gcd(a, b);
	a /= g;
	b /= g;
	return ch(a, b);
}

int main() {
	long long t, a, b;
	for (scanf("%lld", &t); t--; printf("%lld\n", ch(a, b))) scanf("%lld%lld", &a, &b);
}