#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1000][1000], m, n, INF = 987654321;
int *large, *small;

int solve(int a, int b) {
	if (b == m) return 0;
	else if (a >= n || b > m) return INF;

	int &p = dp[a][b];
	if (p != -1) return p;

	return p = min(solve(a + 1, b), solve(a + 1, b + 1) + abs(large[a] - small[b]));
}

int main() {
	scanf("%d%d", &n, &m);
	large = new int[n];
	small = new int[m];
	for (int i = 0; i < n; i++) scanf("%d", large + i);
	for (int i = 0; i < m; i++) scanf("%d", small + i);

	sort(large, large + n);
	sort(small, small + m);
	if (n < m) {
		swap(n, m);
		swap(large, small);
	}

	for (int i = 0; i < n; i++) fill_n(dp[i], m, -1);

	printf("%d", solve(0, 0));
}