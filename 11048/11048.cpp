#include <stdio.h>
#include <algorithm>

using namespace std;

char map[1000][1000];
int n, m, dp[1000][1000];

int solve(int r, int c) {
	if (r == n - 1 && c == m - 1) return dp[r][c] = map[r][c];
	if (r >= n || c >= m) return -2;

	int &p = dp[r][c];
	if (p != -1) return p;

	p = -2;
	const int &r1 = solve(r + 1, c);
	if (r1 != -2) p = r1;

	const int &r2 = solve(r, c + 1);
	if (r2 != -2) p = max(p, r2);

	const int &r3 = solve(r + 1, c + 1);
	if (r3 != -2)p = max(p, r3);

	return p += (p == -2 ? 0 : map[r][c]);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		fill_n(dp[i], m, -1);
		for (int j = 0; j < m; j++) scanf("%d", map[i] + j);
	}

	printf("%d\n", solve(0, 0));
}