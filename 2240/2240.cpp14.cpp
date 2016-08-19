#include <cstdio>
#include <algorithm>

using namespace std;

short t, w, dp[31][1001], plum[1001];

int solve(int t, int w) {
	if (t <= 0 || w < 0) return 0;

	short &p = dp[w][t];
	if (p != -1) return p;
	if (w > t) return p = 0;

	p = max(solve(t - 1, w - 1), solve(t - 1, w));
	if ((plum[t] ^ w) & 1) p++;
	return p;
}

int main() {
	scanf("%hd%hd", &t, &w);
	for (short i = 1; i <= t; i++) scanf("%hd", plum + i);
	for (short i = 0; i <= w; i++) fill_n(dp[i], t + 1, -1);
	printf("%hd", solve(t, w));
}