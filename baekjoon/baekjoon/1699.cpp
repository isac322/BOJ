#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100001];

int solve(int num) {
	int &p = dp[num];
	if (p) return p;

	p = 1 + solve(num - 1);

	for (int i = 2, t = 4; t <= num / 2; i++, t = i * i) {
		p = min(p, solve(t) + solve(num - t));
	}

	return p;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i * i <= n; i++) dp[i * i] = 1;
	printf("%d", solve(n));
}