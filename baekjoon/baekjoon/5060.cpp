#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

bool check[200][200] = { false };
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
	check[n - 1][k - 2] = true;
	dp[n - 1][k - 2] = min;
	return min;
}

int main() {
	int t = 0, n, k, i, j,m;
	double tmp, tmp2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (i = 0; i < n; i++) {
			fill(dp[i], dp[i] + n, 0);
			fill(err[i], err[i] + n, 0);
			fill(check[i], check[i] + n, false);
		}
		for (i = 0; i < n; i++) {
			scanf("%lf", addr + i);

			tmp = addr[i] - addr[0];
			for (j = 1, err[0][i] = 0; j < i; j++) {
				err[0][i] += abs(addr[0] + tmp*j / i - addr[j]);
				tmp2 = addr[i] - addr[j];
				for (m = j + 1; m < i; m++) {
					err[j][i] += abs(addr[j] + tmp2*(m - j) / (i - j) - addr[m]);
				}
			}
			dp[i][0] = err[0][i];
			check[i][0] = true;
		}

		if (!check[n - 1][k - 2]) dp[n - 1][k - 2] = calc(n, k);
		printf("%.4lf\n", dp[n - 1][k - 2] / n);
	}
}