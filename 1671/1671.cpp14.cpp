#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

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

bool prime[2001] = { true,true };

struct Shark {
	size_t a, b, c;

	bool operator>=(const Shark &other) const {
		if (a == other.a && b == other.b && c == other.c) return this < &other;
		return a >= other.a && b >= other.b && c >= other.c;
	}
};

int main() {
	size_t n;
	scanf("%zu", &n);

	Shark *arr = new Shark[n];
	for (size_t i = 0; i < n; i++) scanf("%zu%zu%zu", &arr[i].a, &arr[i].b, &arr[i].c);

	vector<vector<size_t>> graph(n + n + 1);

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++) {
			if (i != j && arr[i] >= arr[j]) {
				graph[i + 1].emplace_back(j + 1);
				graph[i + n + 1].emplace_back(j + 1);
			}
		}
	}

	HopcroftKarp::maximumMatching(graph, n + n, n);
	size_t cnt = 0;
	for (size_t v : HopcroftKarp::pairR) if (v) cnt++;
	printf("%zu", n - cnt);
}