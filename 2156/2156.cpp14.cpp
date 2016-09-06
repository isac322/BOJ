#include <cstdio>
#include <algorithm>

using namespace std;

int cup[10000], dp[10000];

int calc(int idx) {
	int &p = dp[idx];
	if (p) return p;

	dp[idx] = max(calc(idx - 2), calc(idx - 3) + cup[idx - 1]) + cup[idx];
	return dp[idx] = max(dp[idx], calc(idx - 1));
}

int main() {
	int n, i = 0;
	for (scanf("%d", &n); i < n; i++) scanf("%d", cup + i);
	dp[0] = cup[0];
	dp[1] = cup[0] + cup[1];
	dp[2] = max(max(cup[0], cup[1]) + cup[2], dp[1]);
	printf("%d", (n > 3 ? calc(n - 1) : dp[n - 1]));
}