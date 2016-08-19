#include <cstdio>

int n, dp[31] = { 1,1,3 };

int main() {
	for (int i = 3; i < 31; i++) dp[i] = dp[i - 1] + dp[i - 2] * 2;
	scanf("%d", &n);
	printf("%d", dp[n] / 2 + dp[n / 2 + (n & 1 ? 0 : 1)] / 2 + 1);
}