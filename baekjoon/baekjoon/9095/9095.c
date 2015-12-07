#include <stdio.h>

int main() {
	int t, n;
	int dp[11] = { 1, 2, 4 };
	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n - 1]);
	}
}