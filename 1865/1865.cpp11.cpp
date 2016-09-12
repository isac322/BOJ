#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

typedef pair<int, int> PAIR;

const int &INF = numeric_limits<int>::max();

vector<vector<PAIR>> G;

vector<int> dist;

inline void bellman_ford(int start) {
	const size_t &n = G.size();

	dist[start] = 0;

	for (size_t i = 0; i < n - 1; i++) {
		for (size_t here = 0; here < n; here++) {
			if (dist[here] != INF) {
				for (auto &j : G[here]) {
					int there = j.second;
					int weight = j.first;

					dist[there] = min(dist[there], dist[here] + weight);
				}
			}
		}
	}
}

inline bool hasNegativCycle() {
	const size_t &n = G.size();

	for (size_t here = 0; here < n; here++) {
		if (dist[here] != INF) {
			for (auto &j : G[here]) {
				int there = j.second;
				int weight = j.first;

				if (dist[there] > dist[here] + weight) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	int t, n, m, w;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		G.clear();
		scanf("%d %d %d", &n, &m, &w);

		G.resize(n);
		dist.resize(n, INF);

		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			a--, b--;
			G[a].emplace_back(c, b);
			G[b].emplace_back(c, a);
		}
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &a, &b, &c);
			a--, b--;
			G[a].emplace_back(-c, b);
		}
		bellman_ford(0);
		puts(hasNegativCycle() ? "YES" : "NO");
	}
}