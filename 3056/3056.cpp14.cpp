#include <cstdio>
#include <algorithm>

using namespace std;

int n;
double prob[20][20];
double dp[1 << 20];
bool visit[1 << 20];

double solve(int flag, int len) {
	if (visit[flag]) return dp[flag];
	visit[flag] = true;

	if (len == 1) {
		int index = 0;
		int flagT = (~flag) & 0x000fffff;
		for (; !(flagT & 1); flagT >>= 1) index++;
		return dp[flag] = prob[n - 1][index];
	}

	for (int i = 0; i < n; i++) {
		if (!(flag & (1 << i))) {
			dp[flag] = max(dp[flag], solve(flag | (1 << i), len - 1) * prob[n - len][i]);
		}
	}

	return dp[flag] /= 100;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%lf", prob[i] + j);
	}

	printf("%lf", solve(0, n));
}