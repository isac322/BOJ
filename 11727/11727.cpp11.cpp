#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1001] = { 0,1,3,5 }, n;

int solve(int n) {
	int &p = dp[n];
	if (p) return p;

	const int &a = solve(n >> 1), &b = solve((n >> 1) - 1);

	if (n & 1) return p = (a*a + a*b * 4) % 10007;
	else return p = (a*a + b*b * 2) % 10007;
}

int main() {
	scanf("%d", &n);
	printf("%d", solve(n));
}