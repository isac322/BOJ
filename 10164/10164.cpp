#include <cstdio>
#include <algorithm>

using namespace std;

int dp[16][16];

int solve(int n, int m) {
	int &p = dp[n][m];

	if (p) return p;
	if (n == 1 || m == 1) return p = 1;

	for (int i = 1; i <= n; i++) p += solve(i, m - 1);

	return p;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	if (k) {
		k--;
		int x = k%m, y = k / m;
		printf("%d", solve(y + 1, x + 1) * solve(n - y, m - x));
	}
	else {
		printf("%d", solve(n, m));
	}
}