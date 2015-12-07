#include <stdio.h>

int main() {
	int i = 0, n, a, b;
	int cost[300] = { 0 }, dp[300] = { 0 };
	scanf("%d", &n);
	for (; i < n; i++) scanf("%d", cost + i);
	*dp = *cost;
	dp[1] = *cost + cost[1];
	dp[2] = cost[2] + (*cost > cost[1] ? *cost : cost[1]);
	for (i = 3; i < n; i++) {
		a = dp[i - 2];
		b = dp[i - 3] + cost[i - 1];
		dp[i] = (a > b ? a : b) + cost[i];
	}
	printf("%d", dp[n - 1]);
}