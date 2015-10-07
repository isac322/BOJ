#include <cstdio>
#include <algorithm>

using namespace std;

const int fibonacci[] = { 0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657 };
char dp[25001];
int n;

char solve(int val) {
	char &p = dp[val];
	if (p != -1) return p;

	const int *searched = upper_bound(fibonacci, fibonacci + 23, val) - 1;
	int next = solve(val - *searched);

	while ((searched - fibonacci) - next < 2) {
		searched--;
		next = solve(val - *searched);
	}

	return p = int(searched - fibonacci);
}

int k2m(int val) {
	if (val == 0) return 0;

	return fibonacci[dp[val] - 1] + k2m(val - fibonacci[dp[val]]);
}

int main() {
	int t;
	fill(dp, dp + 25001, -1);
	scanf("%d", &t);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	while (t--) {
		scanf("%d", &n);

		solve(n);
		printf("%d\n", k2m(n));
	}
}