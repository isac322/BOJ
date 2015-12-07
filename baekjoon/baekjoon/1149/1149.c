#include <stdio.h>

int price[1000][3] = { 0 };
int dp[1000][3] = { 0 };

int calc(int index, char color) {
	char t = (color + 1) % 3, t1 = (color + 2) % 3;
	int a = dp[index + 1][t] ? dp[index + 1][t] : calc(index + 1, t);
	int b = dp[index + 1][t1] ? dp[index + 1][t1] : calc(index + 1, t1);
	return dp[index][color] = price[index][color] + (a < b ? a : b);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d %d", price[i], &price[i][1], &price[i][2]);
	dp[n - 1][0] = price[n - 1][0];
	dp[n - 1][1] = price[n - 1][1];
	dp[n - 1][2] = price[n - 1][2];
	int a = calc(0, 0), b = calc(0, 1), c = calc(0, 2);
	printf("%d", a < b ? a < c ? a : c : b < c ? b : c);
}