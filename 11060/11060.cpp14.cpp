#include <cstdio>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int n, arr[1000];
const int &INF = numeric_limits<int>::max() >> 1;
int dp[1000];

int solve(int start) {
	if (start >= n - 1) return 1;

	int &ret = dp[start];
	if (ret) return ret;

	const int &left = arr[start];

	if (left == 0) return INF;

	ret = INF;
	for (int i = left; i > 0; i--) {
		const int &v = solve(start + i);

		if (v != -1) ret = min(ret, v + 1);
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	printf("%d", solve(0) == INF ? -1 : solve(0) - 1);
}