#include <stdio.h>

long long arr[1000002] = { 1 };
long long n, p, q, t;

long long calc(long long a) {
	if (a > 1000000) return calc(a / p) + calc(a / q);
	else return arr[a];
}

int main() {
	scanf("%lld %lld %lld", &n, &p, &q);
	t = n > 1000000 ? 1000000 : n;
	for (long long i = 1; i <= t; i++) arr[i] = arr[i / p] + arr[i / q];
	if (n > 1000000) printf("%lld", calc(n));
	else printf("%lld", arr[n]);
}