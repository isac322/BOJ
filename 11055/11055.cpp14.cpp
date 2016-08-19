#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1001], n;
short arr[1001];

int solve(int start) {
	int &p = dp[start];
	if (p && start) return p;

	p = arr[start];
	for (int i = start + 1; i <= n; i++) {
		if (arr[i] > arr[start]) {
			p = max(p, arr[start] + solve(i));
		}
	}
	return p;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%hd", arr + i);
	printf("%d", solve(0));
}