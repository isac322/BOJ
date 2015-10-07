#include <cstdio>
#include <algorithm>

using namespace std;

short map[500][500], n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int dp[500][500];

int solve(int r, int c) {
	if (r == n - 1 && c == m - 1) return 1;

	int &ret = dp[r][c];
	if (ret != -1) return ret;
	ret = 0;

	const short &here = map[r][c];
	for (int i = 0; i < 4; i++) {
		const int &y = r + dx[i];
		const int &x = c + dy[i];

		if (y < 0 || y >= n || x < 0 || x >= m) continue;
		const short &next = map[y][x];

		if (next < here) {
			ret += solve(y, x);
		}
	}

	return ret;
}

int main() {
	scanf("%hd %hd", &n, &m);
	for (int i = 0; i < n; i++) {
		fill_n(dp[i], m, -1);
		for (int j = 0; j < m; j++) scanf("%hd", map[i] + j);
	}
	printf("%d", solve(0, 0));
}