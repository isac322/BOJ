#include <cstdio>

int dp[1000001] = { 0,0,1,1 }, n;

int main() {
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		int &p = dp[i];
		p = dp[i - 1];
		if ((i & 1) == 0 && p > dp[i >> 1]) p = dp[i >> 1];
		if (i % 3 == 0 && p > dp[i / 3]) p = dp[i / 3];
		p++;
	}
	printf("%d", dp[n]);
}