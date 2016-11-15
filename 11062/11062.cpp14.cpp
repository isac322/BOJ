#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000][1000], sum[1001];
short card[1000];

int solve(int left, int right) {
	if (left > right) return 0;
	int &p = dp[left][right];
	if (p) return p;

	return p = sum[right + 1] - sum[left] - min(solve(left, right - 1), solve(left + 1, right));
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%hd", card + i);
			fill_n(dp[i], n, 0);
		}
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + card[i - 1];
		printf("%d\n", solve(0, n - 1));
	}
}