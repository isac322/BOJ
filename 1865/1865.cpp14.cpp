#include <queue>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

typedef pair<int, int> PAIR;

const int &INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> G;
vector<bool> isInQ;
vector<int> dist;
vector<size_t> visits;
size_t n;
deque<size_t> que;

bool spfa() {
	dist[0] = 0;
	isInQ[0] = true;
	que.emplace_back(0);

	while (!que.empty()) {
		size_t here = que.front();
		que.pop_front();
		isInQ[here] = false;

		visits[here]++;
		if (visits[here] > n) return true;

		for (auto edge : G[here]) {
			int next = edge.second;
			int weight = edge.first;

			if (dist[next] > dist[here] + weight) {
				dist[next] = dist[here] + weight;

				if (isInQ[next] == false) {
					que.emplace_back(next);
					isInQ[next] = true;
				}
			}
		}
	}

	return false;
}

int main() {
	int t, m, w;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		G.clear();
		scanf("%zu %d %d", &n, &m, &w);

		G.resize(n);
		dist.resize(n);
		visits.resize(n);
		isInQ.resize(n);
		fill(dist.begin(), dist.end(), INF);
		fill(visits.begin(), visits.end(), 0);
		fill(isInQ.begin(), isInQ.end(), false);
		que.clear();

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
		puts(spfa() ? "YES" : "NO");
	}
}