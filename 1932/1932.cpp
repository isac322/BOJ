#include <stdio.h>

int arr[502][502] = { 0 };
int dp[502][502] = { 0 };
bool check[500][500] = { false };

int calc(int i, int j) {
	int a = check[i + 1][j] ? dp[i + 1][j] : calc(i + 1, j);
	int b = check[i + 1][j + 1] ? dp[i + 1][j + 1] : calc(i + 1, j + 1);
    check[i][j] = true;
	return dp[i][j] = (a > b ? a : b) + arr[i][j];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		dp[n - 1][i] = arr[n - 1][i];
		check[n - 1][i] = true;
	}

	printf("%d", calc(0, 0));
}