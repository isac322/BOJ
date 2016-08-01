#include <cstdio>
#include <algorithm>

using namespace std;

short n, p[1000];
int dp[1001];

int main() {
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) scanf("%hd", p + i);
	for (short mon = 1; mon <= n; mon++) {
		int &t = dp[mon];
		t = p[mon - 1];
		for (short j = 1; j < mon; j++) t = max(t, dp[j] + dp[mon - j]);
	}
	printf("%d", dp[n]);
}