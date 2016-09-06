#include <cstdio>

int dp[1000001] = { 0, 0, 1, 1 }, n, back[1000001] = { 0,-1,1,1 };

void print(int n) {
	if (n == -1) return;
	printf("%d ", n);
	print(back[n]);
}

int main() {
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		int &p = dp[i], &q = back[i];
		p = dp[i - 1];
		q = i - 1;

		if ((i & 1) == 0 && p > dp[i >> 1]) {
			p = dp[i >> 1];
			q = i >> 1;
		}
		if (i % 3 == 0 && p > dp[i / 3]) {
			p = dp[i / 3];
			q = i / 3;
		}
		p++;
	}
	printf("%d\n", dp[n]);
	print(n);
}