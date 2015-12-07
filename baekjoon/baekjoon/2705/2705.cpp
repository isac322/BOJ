#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[1001];
int t, n;

int solve(int num) {
	int &p = dp[num];
	if (p != -1) return p;

	p = 1;
	for (int i = 2; i <= num; i += 2) p += solve(i >> 1);

	return p;
}

int main() {
	scanf("%d", &t);
	fill_n(dp, 1001, -1);
	dp[0] = 0;

	while (t--) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}