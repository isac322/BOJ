#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[111][2][111];

int main() {
	int t;
	scanf("%d", &t);
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][0][j] = dp[i - 1][0][j] + dp[i - 1][1][j];
			dp[i][1][j] += dp[i - 1][0][j];
			dp[i][1][j + 1] += dp[i - 1][1][j];
		}
	}

	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%lld\n", dp[n][0][k] + dp[n][1][k]);
	}
}