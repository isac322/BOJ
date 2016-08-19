#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int t, n, k, a, b, w;
vector<int> pre[1000];
short btime[1000];
int dp[1000];

int solve(int v) {
	int &p = dp[v];
	if (p != -1) return p;
	p = 0;
	for (int q : pre[v]) p = max(p, solve(q));
	return p += btime[v];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		fill_n(dp, n, -1);
		for (int i = 0; i < n; i++) {
			pre[i].clear();
			scanf("%hd", btime + i);
		}
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			a--, b--;
			pre[b].emplace_back(a);
		}
		scanf("%d", &w);
		printf("%d\n", solve(--w));
	}
}