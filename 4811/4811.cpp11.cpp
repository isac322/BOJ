#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[31];

long long solve(long long n) {
	long long &p = dp[n];
	if (p != -1LL) return p;

	p = 0;
	for (long long i = 0; i < n; i++) p += solve(i)*solve(n - i - 1LL);
	return p;
}

int main() {
	long long n;
	fill_n(dp, 31, -1LL);
	dp[0] = 1;

	while (true) {
		scanf("%lld", &n);
		if (n == 0) break;
		else printf("%lld\n", solve(n));
	}
}