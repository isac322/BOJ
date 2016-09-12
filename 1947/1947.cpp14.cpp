#include <cstdio>
#define M 1000000000

int n, dp[1000001] = { 1,0,1 };

int main() {
	long long t;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		t = dp[i - 2] + dp[i - 3];
		dp[i] = int(((i - 1)*(dp[i - 2] + ((i - 2)*t) % M)) % M);
	}
	printf("%d", dp[n]);
}