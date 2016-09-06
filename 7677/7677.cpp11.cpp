#include <cstdio>

short dp[15001] = { 0,1 };

int main() {
	int n;
	for (int i = 2; i < 15001; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10000;
	while (true) {
		scanf("%d", &n);
		if (n == -1) break;

		printf("%hd\n", dp[n % 15000]);
	}
}