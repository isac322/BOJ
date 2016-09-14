#include <cstdio>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

size_t q;

namespace HopcroftKarp {
	const size_t &INF = numeric_limits<size_t>::max();
	const size_t &NIL = 0;

	vector<size_t> pairL, pairR, level;
	queue<size_t> que;
	const vector<vector<size_t>> *graph;
	size_t n, totalMatching;

	inline bool bfs() {
		for (size_t left = 1; left <= n; left++) {
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

			for (size_t right : graph->at((left - 1) % q + 1)) {
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

		for (size_t right : graph->at((left - 1) % q + 1)) {
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
		HopcroftKarp::n = n;

		level.resize(n + 1);
		pairL.resize(n + 1);
		fill(pairL.begin(), pairL.end(), NIL);
		pairR.resize(m + 1);
		fill(pairR.begin(), pairR.end(), NIL);
		totalMatching = 0;

		while (bfs()) {
			for (size_t left = 1; left <= n; left++) {
				if (pairL[left] == NIL && dfs(left)) {
					totalMatching++;
				}
			}
		}

		return totalMatching;
	}
}

int main() {
	size_t n, m, k, t, a;
	scanf("%zu%zu%zu", &n, &m, &k);
	q = n;
	vector<vector<size_t>> graph(n + 1);

	for (size_t i = 1; i <= n; i++) {
		scanf("%zu", &t);
		while (t--) {
			scanf("%zu", &a);
			graph[i].emplace_back(a);
		}
	}

	HopcroftKarp::maximumMatching(graph, n + n, m);
	size_t cnt = 0;
	for (size_t i = 1; i <= n; i++) {
		if (HopcroftKarp::pairL[i]) cnt++;
		if (k && HopcroftKarp::pairL[i + n]) {
			cnt++;
			k--;
		}
	}
	printf("%zu", cnt);
}