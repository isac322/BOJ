#include <cstdio>
#include <algorithm>

using namespace std;

int v[301] = {0};
int dp[301][2] = {0};

int solve(int n, bool is_prev_stepped) {
	int &p = dp[n][is_prev_stepped];
	
	if (p != -1) return p;
	
	int a = is_prev_stepped ? 0 : solve(n - 1, true);
	int b = solve(n - 2, false);
	
	return p = max(a, b) + v[n];
}

int main() {
	int t;
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++) {
		scanf("%d", v + i);
		dp[i][0] = dp[i][1] = -1;
	}
	
	dp[1][0] = dp[1][1] = v[1];
	dp[2][0] = v[1] + v[2];
	
	printf("%d\n", solve(t, false));
}