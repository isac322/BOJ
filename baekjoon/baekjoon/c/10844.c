#include <stdio.h>
#include <memory.h>
#define M 1000000000

int n;
int dp[101][11];

int solve(int left, int prev) {
	int *p = &dp[left][prev];
	if (*p != -1) return *p;

	if (left == 0 || prev > 9 || prev < 0) return *p = 0;
	if (left == 1) return *p = 1;

	return *p = (solve(left - 1, prev - 1) + solve(left - 1, prev + 1)) % M;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) memset(dp[i], -1, 44);
	int sum = 0;
	for (int i = 1; i < 10; i++) sum = (sum + solve(n, i)) % M;

	printf("%d", sum);
}