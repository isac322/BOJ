#include <cstdio>
#include <algorithm>

using namespace std;

bool map[1000][1000];
int n, m, row[1000][1000], column[1000][1000];
pair<int, int> dp[1000][1000];

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = getchar() == '.';
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
	if (map[0][0]) {
		dp[0][0] = { 1,1 };
		ma = 2;
	}
	for (int i = 1; i < m; i++) {
		if (map[0][i]) {
			dp[0][i] = { dp[0][i - 1].first + 1,1 };
			ma = max(ma, dp[0][i].first + dp[0][i].second);
		}
	}
	for (int i = 1; i < n; i++) {
		if (map[i][0]) dp[i][0] = { 1, dp[i - 1][0].second + 1 };
		for (int j = 1; j < m; j++) {
			if (map[i][j]) {
				dp[i][j] = { 1,1 };
				if (dp[i - 1][j - 1].first && dp[i - 1][j - 1].second) {
					if (dp[i - 1][j - 1].first < column[i][j]
						&& dp[i - 1][j - 1].second < row[i][j]) {
						if (dp[i][j].first + dp[i][j].second < dp[i - 1][j - 1].first + 1 + dp[i - 1][j - 1].second + 1) {
							dp[i][j].first = dp[i - 1][j - 1].first + 1;
							dp[i][j].second = dp[i - 1][j - 1].second + 1;
						}
					}
				}
				if (dp[i][j - 1].first && dp[i][j - 1].second) {
					if (dp[i][j - 1].first < column[i][j]
					   && dp[i][j - 1].second <= row[i][j]) {
						if (dp[i][j].first + dp[i][j].second < dp[i][j - 1].first + 1 + dp[i][j - 1].second) {
							dp[i][j].first = dp[i][j - 1].first + 1;
							dp[i][j].second = dp[i][j - 1].second;
						}
					}
				}
				if (dp[i - 1][j].first && dp[i - 1][j].second) {
					if (dp[i - 1][j].first <= column[i][j]
					   && dp[i - 1][j].second < row[i][j]) {
						if (dp[i][j].first + dp[i][j].second < dp[i - 1][j].first + dp[i - 1][j].second + 1) {
							dp[i][j].first = dp[i - 1][j].first;
							dp[i][j].second = dp[i - 1][j].second + 1;
						}
					}
				}
				if (dp[i][j].first + dp[i][j].second < column[i][j] + 1) {
					dp[i][j].first = column[i][j];
					dp[i][j].second = 1;
				}
				if (dp[i][j].first + dp[i][j].second < row[i][j] + 1) {
					dp[i][j].first = 1;
					dp[i][j].second = row[i][j];
				}
				ma = max(ma, dp[i][j].first + dp[i][j].second);
			}
		}
	}

	printf("%d", ma * 2 - 1);
}