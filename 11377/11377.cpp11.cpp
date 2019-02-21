#include <cstdio>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

const size_t &INF = numeric_limits<size_t>::max();

size_t traceLink[2003], flow[2003][2003];

vector<size_t> graph[2003];
deque<size_t> que;
size_t V;

size_t edmondsKarp() {
	que.clear();
	size_t totalFlow = 0;

	while (true) {
		que.clear();
		fill_n(traceLink, V, V);
		traceLink[0] = 0;

		que.emplace_back(0);

		while (!que.empty()) {
			size_t here = que.front();
			if (here == V - 2) break;
			que.pop_front();

			for (size_t there : graph[here]) {
				if (flow[here][there] > 0 && traceLink[there] == V) {
					que.emplace_back(there);
					traceLink[there] = here;
				}
			}
		}

		if (traceLink[V - 2] == V) break;

		size_t amount = INF;
		for (size_t u = V - 2; u != 0; u = traceLink[u]) {
			size_t &v = traceLink[u];
			amount = min(amount, flow[v][u]);
		}

		for (size_t u = V - 2; u != 0; u = traceLink[u]) {
			size_t &v = traceLink[u];
			flow[v][u] -= amount;
			flow[u][v] += amount;
		}

		totalFlow += amount;
	}

	return totalFlow;
}

int main() {
	size_t n, m, k;
	scanf("%zu%zu%zu", &n, &m, &k);

	size_t t, a;
	for (size_t i = 1; i <= n; i++) {
		graph[0].emplace_back(i);
		graph[i].emplace_back(0);
		graph[n + m + 2].emplace_back(i);
		graph[i].emplace_back(n + m + 2);
		flow[0][i] = flow[n + m + 2][i] = 1;
		scanf("%zu", &t);
		while (t--) {
			scanf("%zu", &a);
			graph[i].emplace_back(a + n);
			graph[a + n].emplace_back(i);
			flow[i][a + n] = 1;
		}
	}
	graph[0].emplace_back(n + m + 2);
	graph[n + m + 2].emplace_back(0);
	flow[0][n + m + 2] = k;
	for (size_t i = 1; i <= m; i++) {
		graph[i + n].emplace_back(n + m + 1);
		graph[n + m + 1].emplace_back(i + n);
		flow[i + n][n + m + 1] = 1;
	}

	V = m + n + 3;

	printf("%zu", edmondsKarp());
}