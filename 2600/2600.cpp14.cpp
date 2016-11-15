#include <cstdio>
#include <algorithm>

using namespace std;

int b[3], k[2];
bool dp[501][501], visit[501][501];

bool solve(int l, int r) {
	if (l < 0 || r < 0) return true;
	bool &ret = dp[l][r];
	if (visit[l][r]) return ret;
	visit[l][r] = true;
	return ret = !(solve(l - b[0], r) && solve(l, r - b[0]) && solve(l - b[1], r) && solve(l, r - b[1]) && solve(l - b[2], r) && solve(l, r - b[2]));
}

int main() {
	scanf("%d%d%d", b, b + 1, b + 2);
	for (int j = 0; j < 5; j++) {
		scanf("%d%d", k, k + 1);
		for (int i = 0; i <= k[0]; i++) fill_n(visit[i], k[1] + 1, false);
		puts(solve(k[0], k[1]) ? "A" : "B");
	}
}