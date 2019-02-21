#include <queue>
#include <vector>
#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

typedef pair<int, int> PAIR;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, size_t>>> graph;

deque<size_t> que;
vector<bool> isInQ;
vector<int> dist;
vector<size_t> visits;

size_t n, e, a, b;
int c;

inline void spfa() {
	dist[0] = 0;
	isInQ[0] = true;
	que.emplace_back(0);

	while (!que.empty()) {
		size_t here = que.front();
		que.pop_front();
		isInQ[here] = false;

		visits[here]++;
		if (visits[here] == n) return;

		for (auto edge : graph[here]) {
			size_t next = edge.second;
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
}

inline bool hasNegativCycle() {
	for (auto v : visits) if (v == n) return true;
	return false;
}

int main() {
	scanf("%zu%zu", &n, &e);
	graph.resize(n);
	dist.resize(n, INF);
	isInQ.resize(n, false);
	visits.resize(n, 0);
	while (e--) {
		scanf("%zu%zu%d", &a, &b, &c);
		a--, b--;
		graph[a].emplace_back(c, b);
	}
	spfa();
	if (hasNegativCycle()) puts("-1");
	else for (size_t i = 1; i < n; i++) printf("%d\n", dist[i] == INF ? -1 : dist[i]);
}