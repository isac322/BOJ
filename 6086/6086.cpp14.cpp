#include <queue>
#include <limits>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

size_t flow[52][52];

const size_t &INF = numeric_limits<size_t>::max();

vector<size_t> traceLink;

deque<size_t> que;

size_t edmondsKarp(const vector<vector<size_t>> &graph, size_t source, size_t sink) {
	const size_t &V = graph.size();
	traceLink.resize(V);

	size_t totalFlow = 0;

	while (true) {
		que.clear();
		fill(traceLink.begin(), traceLink.end(), V);

		que.emplace_back(source);

		while (!que.empty()) {
			size_t here = que.front();
			if (here == sink) break;
			que.pop_front();

			for (size_t there : graph[here]) {
				if (flow[here][there] > 0 && traceLink[there] == V) {
					que.emplace_back(there);
					traceLink[there] = here;
				}
			}
		}

		if (traceLink[sink] == V) break;

		size_t amount = INF;
		for (size_t u = sink; u != source; u = traceLink[u]) {
			size_t &v = traceLink[u];
			amount = min(amount, flow[v][u]);
		}

		for (size_t u = sink; u != source; u = traceLink[u]) {
			size_t &v = traceLink[u];
			flow[v][u] -= amount;
			flow[u][v] += amount;
		}

		totalFlow += amount;
	}

	return totalFlow;
}


inline int convert(char c) {
	if (c >= 'a' && c <= 'z') return c - 'a' + 26;
	else if (c >= 'A' && c <= 'Z') return c - 'A';
}

int main() {
	char a, b;
	size_t n, t;
	scanf("%zu", &n);
	vector<vector<size_t>> graph(52);
	for (size_t i = 0; i < n; i++) {
		getchar();
		scanf("%c %c %zu", &a, &b, &t);
		a = convert(a);
		b = convert(b);
		graph[a].emplace_back(b);
		flow[a][b] += t;
	}
	printf("%zu", edmondsKarp(graph, 0, 25));
}