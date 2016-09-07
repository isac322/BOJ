#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000][3], n, price[1000][3];

int solve(int idx, int prev) {
	if (idx < 0) return 0;
	int &p = dp[idx][prev];
	if (p) return p;
	return p = min(solve(idx - 1, (prev + 1) % 3) + price[idx][(prev + 1) % 3],
				   solve(idx - 1, (prev + 2) % 3) + price[idx][(prev + 2) % 3]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", price[i], price[i] + 1, price[i] + 2);
	printf("%d", min(solve(n - 1, 0), min(solve(n - 1, 1), solve(n - 1, 2))));
}