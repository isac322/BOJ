#include <cstdio>
#include <algorithm>

using namespace std;

int dp[300001] = { 0 };
int arr[122] = { 0 };

int solve(int n) {
	if (n == 0) return 0;

	int &p = dp[n];
	if (p) return p;

	int ret = 987654321;
	for (int i = 1; arr[i] <= n; i++) {
		ret = min(ret, solve(n - arr[i]));
	}

	return p = ret + 1;
}

int main() {
	int n;
	for (int i = 1; i <= 121; i++) {
		arr[i] = i*(i + 1)*(i + 2) / 6;
	}
	scanf("%d", &n);
	printf("%d\n", solve(n));
}