#include <stdio.h>

int main() {
	int n, i = 1;
	int dp[3] = { 0 }, dp2[3] = { 0 }, val[3], tmp[2] = { 0 };
	scanf("%d\n%d %d %d", &n, dp, dp + 1, dp + 2);
	*dp2 = *dp;
	dp2[1] = dp[1];
	dp2[2] = dp[2];
	for (; i < n; i++) {
		scanf("%d %d %d", val, val + 1, val + 2);
		tmp[0] = dp[0] > dp[1] ? dp[0] : dp[1];
		tmp[1] = tmp[0] > dp[2] ? tmp[0] : dp[2];
		dp[2] = (dp[1] > dp[2] ? dp[1] : dp[2]) + val[2];
		dp[0] = tmp[0] + val[0];
		dp[1] = tmp[1] + val[1];

		tmp[0] = dp2[0] < dp2[1] ? dp2[0] : dp2[1];
		tmp[1] = tmp[0] < dp2[2] ? tmp[0] : dp2[2];
		dp2[2] = (dp2[1] < dp2[2] ? dp2[1] : dp2[2]) + val[2];
		dp2[0] = tmp[0] + val[0];
		dp2[1] = tmp[1] + val[1];
	}
	printf("%d ", dp[0] > dp[1] ? dp[0] > dp[2] ? dp[0] :dp[2] : dp[1] > dp[2] ? dp[1] : dp[2]);
	printf("%d\n", dp2[0] < dp2[1] ? dp2[0] < dp2[2] ? dp2[0] : dp2[2] : dp2[1] < dp2[2] ? dp2[1] : dp2[2]);
}