#include <cstdio>
#define M 10007

short n, k, dp[1001] = { 1 };

int main() {
	scanf("%hd%hd", &n, &k);
	for (short i = 0; i < n; i++) {
		dp[i + 1] = 1;
		for (short j = i; j > 0; j--) dp[j] = (dp[j] + dp[j - 1]) % M;
	}
	printf("%hd", dp[k]);
}