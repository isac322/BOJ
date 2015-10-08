#include <stdio.h>

long long dp[91] = { 0, 1, 1 };

long long fi(int n) {
	if (n < 3) return dp[n];
	return dp[n] = (dp[n - 1] ? dp[n - 1] : fi(n - 1)) + (dp[n - 2] ? dp[n - 2] : fi(n - 2));
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", fi(n));
}