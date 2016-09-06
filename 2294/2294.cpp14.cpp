#include <cstdio>
#include <algorithm>

using namespace std;


int n, k, dp[10'001] = { 0 }, coins[100];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", coins + i);
	fill_n(dp + 1, k, 1987654321);

	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}
	printf("%d", dp[k] == 1987654321 ? -1 : dp[k]);
}