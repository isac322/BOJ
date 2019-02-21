#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100001];

int solve(int num) {
	int &p = dp[num];
	if (p) return p;

	p = 1 + solve(num - 1);

	for (int i = 2; i * i <= num / 2; i++) {
		p = min(p, solve(i * i) + solve(num - i * i));
	}

	return p;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 317; i++) dp[i * i] = 1;
	printf("%d", solve(n));
}