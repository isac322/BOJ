#include <cstdio>
#include <algorithm>

using namespace std;

int mat[100][100], n;
long long dp[100][100];

long long solve(int y, int x) {
	if (y == n - 1 && x == n - 1) return 1LL;
	if (y >= n || x >= n) return -1LL;

	if (dp[y][x] != -1) return dp[y][x];

	int &val = mat[y][x];
	long long a = solve(y + val, x);
	long long b = solve(y, x + val);

	return dp[y][x] = (a > 0 ? a : 0) + (b > 0 ? b : 0);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		fill(dp[i], dp[i] + n, -1);
		for (int j = 0; j < n; j++) {
			scanf("%d", mat[i] + j);
			if (mat[i][j] == 0) dp[i][j] = 0;
		}
	}
	printf("%lld", solve(0, 0));
}