#include <cstdio>

typedef long long T;

T gcd(T a, T b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	T a, b, c, n1, n2;
	scanf("%lld%lld", &a, &b);
	n1 = a;
	n2 = b;
	b *= a;
	for (T i = a; i <= b; i += a) {
		if (b % i) continue;
		else if (i > (c = b / i)) break;
		else if (gcd(i, c) != a) continue;
		else if (n1 + n2 > i + c) n1 = i, n2 = c;
	}
	printf("%lld %lld", n1, n2);
}