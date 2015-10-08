#include <stdio.h>
#include <math.h>
#include <memory.h>

char check[200][200] = { 0 };
double dp[200][200] = { 0 };
double err[200][200] = { 0 };
double addr[200] = { 0 };

double calc(int n, int k) {
	double min = 1e16, tmp;
	for (int i = k - 2; i < n - 1; i++) {
		if (!check[i][k - 3]) dp[i][k - 3] = calc(i + 1, k - 1);
		tmp = dp[i][k - 3] + err[i][n - 1];
		if (tmp < min) min = tmp;
	}
	check[n - 1][k - 2] = 1;
	dp[n - 1][k - 2] = min;
	return min;
}

int main() {
	int t, n, k, i, j, m;
	double tmp, tmp2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) {
			memset(dp[i], 0, sizeof(double)*n);
			memset(err[i], 0, sizeof(double)*n);
			memset(check[i], 0, sizeof(char)*n);
		}
		for (i = 0; i < n; i++) {
			scanf("%lf", addr + i);

			tmp = addr[i] - addr[0];
			for (j = 1, err[0][i] = 0; j < i; j++) {
				err[0][i] += fabs(addr[0] + tmp*j / i - addr[j]);
				tmp2 = addr[i] - addr[j];
				for (m = j + 1; m < i; m++) {
					err[j][i] += fabs(addr[j] + tmp2*(m - j) / (i - j) - addr[m]);
				}
			}
			dp[i][0] = err[0][i];
			check[i][0] = 1;
		}

		if (!check[n - 1][k - 2]) dp[n - 1][k - 2] = calc(n, k);
		printf("%.4lf\n", dp[n - 1][k - 2] / n);
	}
}