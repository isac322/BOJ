#include <cstdio>

int main() {
	long long c, r, n;
	scanf("%lld%lld%lld", &c, &r, &n);
	printf("%lld", (c / n) * (r / n) + (r % n ? c / n : 0) + (c % n ? r / n : 0) + (c % n && r % n ? 1 : 0));
}