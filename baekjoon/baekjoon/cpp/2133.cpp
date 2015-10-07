#include <cstdio>
#include <algorithm>

using namespace std;

int dp[31];
int n;

int solve(int len) {
	if (len == 0) return 1;

	int &p = dp[len];
	if (p) return p;

	p = solve(len - 2) * 3;
	for (int i = 4; i <= len; i += 2) {
		p += solve(len - i) * 2;
	}

	return p;
}

int main() {
	scanf("%d", &n);
	if (n & 1) {
		puts("0");
		return 0;
	}

	dp[2] = 3;
	dp[4] = 11;
	printf("%d", solve(n));
}