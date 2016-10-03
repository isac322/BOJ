#include <cstdio>
#include <algorithm>

using namespace std;

size_t match[1000001] = { 1000000 }, n, ma, dp[1000000], arr[1000000];

int main() {
	scanf("%zu", &n);
	for (size_t i = 0; i < n; i++) {
		scanf("%zu", arr + i);
		match[arr[i]] = i;
	}
	for (size_t i = 0; i < n; i++) {
		dp[i] = 1;
		if (match[arr[i] - 1] < i) dp[i] = max(dp[i], dp[match[arr[i] - 1]] + 1);
		ma = max(ma, dp[i]);
	}
	printf("%zu", n - ma);
}