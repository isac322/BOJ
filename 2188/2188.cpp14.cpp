#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<size_t>> g;
vector<size_t> matchLink;
vector<bool> visit;
size_t n, m, t, a;

bool dfs(size_t node) {
	if (visit[node]) return false;
	visit[node] = true;

	for (auto next : g[node]) {
		if (matchLink[next] == n || dfs(matchLink[next])) {
			matchLink[next] = node;
			return true;
		}
	}

	return false;
}

inline size_t maximumMatching() {
	size_t cnt = 0;
	for (size_t i = 0; i < n; i++) {
		fill(visit.begin(), visit.end(), false);
		if (dfs(i)) cnt++;
	}

	return cnt;
}

int main() {
	scanf("%zu%zu", &n, &m);
	g.resize(n);
	visit.resize(n);
	matchLink.resize(n, n);

	for (size_t i = 0; i < m; i++) {
		scanf("%zu", &t);
		while (t--) {
			scanf("%zu", &a);
			a--;
			g[i].emplace_back(a);
		}
	}

	printf("%zu", maximumMatching());
}