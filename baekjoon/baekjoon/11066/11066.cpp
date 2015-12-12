#include <cstdio>
#include <algorithm>
#include <limits>

using namespace std;

int dp[500][500], sum[501];
const int &INF = numeric_limits<int>::max();

int solve(int start, int end) {
	int &p = dp[start][end];
	if (p != -1) return p;

	p = INF;

	for (int i = start; i < end; i++) {
		p = min(p, solve(start, i) + solve(i + 1, end));
	}

	return p += sum[end + 1] - sum[start];
}

int main() {
	int t, n, z;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			fill_n(dp[i] + i, n - i, -1);
			dp[i][i] = 0;

			scanf("%d", &z);

			sum[i + 1] = sum[i] + z;
		}

		printf("%d\n", solve(0, n - 1));
	}
}