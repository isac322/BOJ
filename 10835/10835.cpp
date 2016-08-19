#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

short n;
vector<short> left, right;
int dp[2000][2000];

int solve(short l_top, short r_top) {
	if (l_top == -1 || r_top == -1) return 0;

	int &p = dp[l_top][r_top];
	if (p != -1) return p;

	int ret = solve(l_top - 1, r_top);

	ret = max(ret, solve(l_top - 1, r_top - 1));

	if (right[r_top] < left[l_top]) {
		ret = max(ret, solve(l_top, r_top - 1) + right[r_top]);
	}

	return p = ret;
}

int main() {
	scanf("%hd", &n);
	left.resize(n);
	right.resize(n);

	for (short i = 0; i < n; i++) {
		fill(dp[i], dp[i] + n, -1);
		scanf("%hd", &left[n - i - 1]);
	}
	for (short i = 0; i < n; i++) scanf("%hd", &right[n - i - 1]);

	printf("%d\n", solve(n - 1, n - 1));
}