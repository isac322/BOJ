#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	int a[101], dp[10001] = { 1 };
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", a + i);

	for (int i = 0; i < n; i++) {
		for (int j = a[i]; j <= k; j++) {
			dp[j] += dp[j - a[i]];
		}
	}
	printf("%d", dp[k]);
}