#include <stdio.h>
#define max(a,b) a > b ? a : b

int cup[10000] = { 0 };
int dp[10000] = { 0 };

int calc(int index) {
	int a = (dp[index - 2] ? dp[index - 2] : calc(index - 2));
	int b = (dp[index - 3] ? dp[index - 3] : calc(index - 3)) + cup[index - 1];
	int c = (dp[index - 1] ? dp[index - 1] : calc(index - 1));
	dp[index] = max(a, b);
	dp[index] += cup[index];
	dp[index] = max(dp[index], c);
	return dp[index];
}

int main() {
	int n, i = 0;
	for (scanf("%d", &n); i < n; i++) {
		dp[i] = 0;
		scanf("%d", cup + i);
	}
	dp[0] = cup[0];
	dp[1] = cup[0] + cup[1];
	dp[2] = max(cup[0], cup[1]);
	dp[2] += cup[2];
	dp[2] = max(dp[2], dp[1]);
	int a = (n > 3 ? calc(n - 1) : dp[n - 1]);
	printf("%d", a);
}