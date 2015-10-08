#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char map[100000][3];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%hhd %hhd %hhd", map[i], map[i] + 1, map[i] + 2);

	int dp[3] = { 0 }, ne[3];
	for (int i = n - 1; i >= 0; i--) {
		ne[0] = max(dp[0], dp[1]) + map[i][0];
		ne[1] = max(dp[0], dp[1]);
		ne[1] = max(ne[1], dp[2]) + map[i][1];
		ne[2] = max(dp[1], dp[2]) + map[i][2];

		dp[0] = ne[0];
		dp[1] = ne[1];
		dp[2] = ne[2];
	}

	int dp2[3] = { 0 };
	for (int i = n - 1; i >= 0; i--) {
		ne[0] = min(dp2[0], dp2[1]) + map[i][0];
		ne[1] = min(dp2[0], dp2[1]);
		ne[1] = min(ne[1], dp2[2]) + map[i][1];
		ne[2] = min(dp2[1], dp2[2]) + map[i][2];

		dp2[0] = ne[0];
		dp2[1] = ne[1];
		dp2[2] = ne[2];
	}

	printf("%d %d", max(max(dp[0], dp[1]), dp[2]), min(min(dp2[0], dp2[1]), dp2[2]));
}