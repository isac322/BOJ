#include <cstdio>
#include <algorithm>

using namespace std;

unsigned long long dp[18][18];

unsigned long long solve(int n, int k) {
	if (dp[n][k]) return dp[n][k];
	
	return dp[n][k] = solve(n, k - 1) - solve(n - 1, k - 1);
}

int main() {
	int t;
	unsigned long long f = 1;
	scanf("%d", &t);
	
	for (int i = 0; i < 18; f *= ++i) dp[i][0] = f;
	
	for (int c = 1; c <= t; c++) {
		int n, k;
		scanf("%d%d%d", &c, &n, &k);
		printf("%d %llu\n", c, solve(n, k));
	}
}