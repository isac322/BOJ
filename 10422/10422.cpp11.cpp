#include <cstdio>
#include <algorithm>

using namespace std;
#define M 1000000007

long long dp[2501];

long long solve(int n) {
	long long &p = dp[n];
	if (p != -1) return p;

	p = 0;
	for (int i = 0; i < n; i++) p = (p + solve(i)*solve(n - i - 1)) % M;
	return p;
}

int main() {
	int t, n;
	scanf("%d", &t);

	fill_n(dp, 2501, -1);
	dp[0] = 1;

	while (t--) {
		scanf("%d", &n);
		if (n & 1) puts("0");
		else printf("%lld\n", solve(n >> 1));
	}
}