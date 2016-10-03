#include <cstdio>
#include <algorithm>

using namespace std;

bool map[1000][1000];
int n, m, row[1000][1000], column[1000][1000], dp[1000][1000];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = getchar() == '1';
			if (map[i][j]) {
				if (i) row[i][j] = row[i - 1][j] + 1;
				else row[i][j] = 1;
				if (j) column[i][j] = column[i][j - 1] + 1;
				else column[i][j] = 1;
			}
		}
		getchar();
	}

	int ma = 0;
	for (int i = 0; i < m; i++) if (map[0][i]) ma = dp[0][i] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				if (j) dp[i][j] = max(1, min(dp[i - 1][j - 1] + 1, min(row[i][j], column[i][j])));
				else dp[i][j] = 1;
				ma = max(ma, dp[i][j]);
			}
		}
	}

	printf("%d", ma*ma);
}