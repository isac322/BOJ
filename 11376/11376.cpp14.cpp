#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const size_t &INF = numeric_limits<size_t>::max();

size_t V, n, m;
vector<size_t> traceLink;
vector<vector<size_t>> graph;
size_t flow[2002][2002];

int main() {
	scanf("%zu%zu", &n, &m);
	V = n + m + 2;
	graph.resize(V);
	traceLink.resize(V);

	size_t t, a;
	for (size_t i = 1; i <= n; i++) {
		graph[0].emplace_back(i);
		flow[0][i] = 2;

		scanf("%zu", &t);
		for (size_t j = 0; j < t; j++) {
			scanf("%zu", &a);
			graph[i].emplace_back(a + n);
			graph[a + n].emplace_back(i);;
			flow[i][a + n] = 1;
		}
	}
	for (size_t i = 1; i <= m; i++) {
		graph[i + n].emplace_back(V - 1);
		flow[i + n][V - 1] = 1;
	}

	size_t totalFlow = 0;
	deque<size_t> que;

	while (true) {
		que.clear();
		fill(traceLink.begin(), traceLink.end(), V);

		que.emplace_back(0);

		while (!que.empty()) {
			size_t here = que.front();
			if (here == V - 1) break;
			que.pop_front();

			for (auto there : graph[here]) {
				if (flow[here][there] > 0 && traceLink[there] == V) {
					que.emplace_back(there);
					traceLink[there] = here;
				}
			}
		}

		if (traceLink[V - 1] == V) break;

		size_t amount = INF;
		for (size_t u = V - 1; u != 0; u = traceLink[u]) {
			size_t &v = traceLink[u];
			amount = min(amount, flow[v][u]);
		}

		for (size_t u = V - 1; u != 0; u = traceLink[u]) {
			size_t &v = traceLink[u];
			flow[v][u] -= amount;
			flow[u][v] += amount;
		}

		totalFlow += amount;
	}

	printf("%zu", totalFlow);
}