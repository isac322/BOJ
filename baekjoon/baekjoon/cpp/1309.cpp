#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define M 9901

int n;
short dp[100001][3];

short solve(int left, int prev) {
	short &p = dp[left][prev];
	if (p != -1) return p;
	p = 0;

	switch (prev) {
		case 0:
			return p = (solve(left - 1, 0) + solve(left - 1, 1) + solve(left - 1, 2)) % M;
		case 1:
			return p = (solve(left - 1, 0) + solve(left - 1, 2)) % M;
		case 2:
			return p = (solve(left - 1, 0) + solve(left - 1, 1)) % M;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) fill_n(dp[i], 3, -1);
	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	printf("%d", solve(n, 0));
}