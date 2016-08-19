#include <cstdio>
#include <algorithm>

using namespace std;
#define M 1000000007

int dp1[2501], dp2[2501];

int solve(int n);
long long solve2(int n) {
	int &p = dp2[n];
	if (p != -1) return p;
	else return p = solve(n - 1);
}

int solve1(int n) {
	int &p = dp1[n];
	if (p != -1) return p;

	p = 0;
	for (int i = 1; i < n; i++) {
		p = (p + solve(i) * solve2(n - i)) % M;
	}

	return p;
}

inline int solve(int n) {
	if (n == 1) return 1;
	return (solve1(n) + solve2(n)) % M;
}

int main() {
	int t, n;
	scanf("%d", &t);

	fill_n(dp1, 2501, -1);
	fill_n(dp2, 2501, -1);
	dp2[1] = dp1[1] = 1;
	dp1[0] = dp2[0] = 0;

	while (t--) {
		scanf("%d", &n);
		if (n & 1) puts("0");
		else printf("%d\n", solve(n >> 1));
	}
}