#include <cstdio>
#include <algorithm>
#define M 1000000000

using namespace std;

int dp[201][201], n;

int solve(int num, int k) {
	if (k < 0 || num < 0) return 0;
	int &p = dp[k][num];
	if (p != -1) return p;

	p = 0;
	for (int i = 0; i <= num; i++) p = (p + solve(num - i, k - 1)) % M;
	return p;
}

int main() {
	int k;
	scanf("%d%d", &n, &k);
	dp[0][0] = 1;
	fill_n(dp[1], n + 1, 1);
	for (int i = 2; i <= k; i++) fill_n(dp[i], n + 1, -1);
	printf("%d", solve(n, k));
}