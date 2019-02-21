#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

namespace HopcroftKarp {
	using namespace std;

	const size_t &INF = numeric_limits<size_t>::max();
	vector<size_t> pairL, pairR, level;
	queue<size_t> que;
	const vector<vector<size_t>> *graph;
	size_t nL, NIL, totalMatching;

	inline bool bfs() {
		for (size_t left = 0; left < nL; left++) {
			if (pairL[left] == NIL) {
				level[left] = 0;
				que.emplace(left);
			}
			else level[left] = INF;
		}
		level[NIL] = INF;

		while (que.size()) {
			size_t left = que.front();
			que.pop();

			if (level[left] >= level[NIL]) continue;

			for (size_t right : graph->at(left)) {
				size_t prevPair = pairR[right];

				if (level[prevPair] == INF) {
					level[prevPair] = level[left] + 1;
					que.emplace(prevPair);
				}
			}
		}

		return level[NIL] != INF;
	}

	bool dfs(size_t left) {
		if (left == NIL) return true;

		for (size_t right : graph->at(left)) {
			size_t &traceLink = pairR[right];

			if (level[traceLink] == level[left] + 1 && dfs(traceLink)) {
				traceLink = left;
				pairL[left] = right;
				return true;
			}
		}

		level[left] = INF;
		return false;
	}

	size_t maximumMatching(const vector<vector<size_t>> &graph, size_t n, size_t m) {
		HopcroftKarp::graph = &graph;
		nL = n;

		NIL = n + 10;
		level.resize(NIL + 1);
		pairL.resize(n);
		fill(pairL.begin(), pairL.end(), NIL);
		pairR.resize(m);
		fill(pairR.begin(), pairR.end(), NIL);
		totalMatching = 0;

		while (bfs()) {
			for (size_t left = 0; left < n; left++) {
				if (pairL[left] == NIL && dfs(left)) {
					totalMatching++;
				}
			}
		}

		return totalMatching;
	}
}

int main() {
	size_t n, m, t, a;
	scanf("%zu%zu", &n, &m);
	vector<vector<size_t>> graph(n);

	for (size_t i = 0; i < n; i++) {
		scanf("%zu", &t);
		while (t--) {
			scanf("%zu", &a);
			graph[i].emplace_back(--a);
		}
	}

	printf("%zu", HopcroftKarp::maximumMatching(graph, n, m));
}