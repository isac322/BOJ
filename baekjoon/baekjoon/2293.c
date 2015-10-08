#include <stdio.h>

int coin[20] = { 0 };
int dp[10001] = { 1 };
int mon;

int main() {
	int i, j, n;
	scanf("%d%d", &n,&mon);
	for (i = 0; i < n; i++) scanf("%d", coin + i);
	for (i = 0; i < n; i++) for (j = coin[i]; j <= mon; j++) dp[j] += dp[j - coin[i]];
	printf("%d", dp[mon]);
}