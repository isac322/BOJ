#include <stdio.h>

int main() {
	int dp[] = { 1, 2 }, n, t;
	scanf("%d", &n);
	for (int i = 2; i < n; i++) {
		t = dp[1];
		dp[1] = (dp[0] + dp[1]) % 15746;
		dp[0] = t;
	}
	printf("%d", dp[1]);
}