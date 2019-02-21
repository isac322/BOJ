#include <cstdio>
#include <algorithm>

#define NONE 0
#define UP 1
#define DOWN 2

using namespace std;

int n;
short stiker[2][100000];
int dp[100000][3];

int solve(int start, int prev) {
	if (start == n) return 0;

	int &ret = dp[start][prev];
	if (ret != -1) return ret;

	switch (prev) {
		case NONE:
			ret = max(solve(start + 1, UP) + stiker[0][start], solve(start + 1, DOWN) + stiker[1][start]);
			ret = max(ret, solve(start + 1, NONE));
			return ret;

		case UP:
			return ret = max(solve(start + 1, DOWN) + stiker[1][start], solve(start + 1, NONE));

		case DOWN:
			return ret = max(solve(start + 1, UP) + stiker[0][start], solve(start + 1, NONE));
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%hd", stiker[0] + i);
		for (int i = 0; i < n; i++) {
			fill_n(dp[i], 3, -1);
			scanf("%hd", stiker[1] + i);
		}

		printf("%d\n", solve(0, NONE));
	}
}