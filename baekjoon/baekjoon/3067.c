#include <stdio.h>
#include <memory.h>

int coin[20] = { 0 };
int dp[10001] = { 1 };
int mon;

int main() {
	int i, j, n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d", coin + i);
		scanf("%d", &mon);
		memset(dp + 1, 0, sizeof(int)*mon);
		for (i = 0; i < n; i++) {
			for (j = coin[i]; j <= mon; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		printf("%d\n", dp[mon]);
	}
}