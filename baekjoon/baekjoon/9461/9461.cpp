#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[101] = { 0,1,1,1,2,2,3 };

long long solve(int n) {
	if (dp[n]) return dp[n];
	return dp[n] = solve(n - 1) + solve(n - 5);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);

		printf("%lld\n", solve(n));
	}
}