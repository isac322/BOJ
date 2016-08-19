#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, l, g;
short mapR[100][100], mapD[100][100];
int dp[100][100][2][201];
const int INF = 987654321;

int solve(int r, int c, int k, bool right) {
	if (r >= m || c >= n) return INF;
	if (k < 0) return INF;

	int &p = dp[r][c][right ? 1 : 0][k];
	if (p != -1) return p;
	p = INF;

	if (r == m - 1 && c == n - 1) return p = k == 0 ? 0 : INF;

	if (right) {
		p = min(p, mapR[r][c] + solve(r, c + 1, k, true));
		p = min(p, mapD[r][c] + solve(r + 1, c, k - 1, false));
	}
	else {
		p = min(p, mapR[r][c] + solve(r, c + 1, k - 1, true));
		p = min(p, mapD[r][c] + solve(r + 1, c, k, false));
	}

	return p;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d%d%d", &m, &n, &l, &g);
		for (int i = 0; i < m; i++) for (int j = 0; j < n - 1; j++) scanf("%hd", mapR[i] + j);
		for (int i = 0; i < m - 1; i++) for (int j = 0; j < n; j++) scanf("%hd", mapD[i] + j);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				fill_n(dp[i][j][0], n + m - 2, -1);
				fill_n(dp[i][j][1], n + m - 2, -1);
			}
		}

		int turn = 0;
		for (; turn < n + m - 2; turn++) {
			if (solve(0, 0, turn, false) <= g || solve(0, 0, turn, true) <= g) {
				printf("%d\n", turn + (n + m - 2)*l);
				break;
			}
		}

		if (turn == n + m - 2) puts("-1");
	}
}