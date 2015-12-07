#include <cstdio>
#include <algorithm>

using namespace std;

int dp[41][2] = { {0,0},{0,1} };
int n, m;

int solve(int n, int right) {
	if (n == 1 && right == 0) return 0;

	int &p = dp[n][right];
	if (p) return p;

	if (right) p += solve(n - 1, 0) + solve(n - 1, 1);
	else p += solve(n - 1, 1);

	return p;
}

int main() {
	int t;
	scanf("%d%d", &n, &m);

	int prev = 0, sum = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (t - prev != 1) sum *= solve(t - prev - 1, 0) + solve(t - prev - 1, 1);
		prev = t;
	}

	if (n != prev)sum *= solve(n - prev, 0) + solve(n - prev, 1);
	printf("%d", sum);
}