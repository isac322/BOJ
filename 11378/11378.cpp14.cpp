#include <cstdio>
#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

size_t q;
size_t n, m, k, t, a, j = 0;
vector<vector<size_t>> graph;

const size_t &INF = numeric_limits<size_t>::max();
const size_t &NIL = 0;

vector<size_t> pairL, pairR, level;
queue<size_t> que;
size_t totalMatching;

inline bool bfs() {
	for (size_t left = 1; left <= n; left++) {
		if (pairL[left + j] == NIL) {
			level[left + j] = 0;
			que.emplace(left + j);
		}
		else level[left + j] = INF;
	}
	level[NIL] = INF;

	while (que.size()) {
		size_t left = que.front();
		que.pop();

		if (level[left] >= level[NIL]) continue;

		for (size_t right : graph[(left - 1) % q + 1]) {
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

	for (size_t right : graph[(left - 1) % q + 1]) {
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

void maximumMatching(size_t n, size_t m) {
	while (bfs()) {
		for (size_t left = 1; left <= n; left++) {
			if (pairL[left] == NIL && dfs(left)) {
				totalMatching++;
			}
		}
	}
}


int main() {
	scanf("%zu%zu%zu", &n, &m, &k);
	q = n;
	graph.resize(n + 1);
	level.resize(n + n*k + 1);
	pairL.resize(n + n*k + 1, 0);
	pairR.resize(m + 1, 0);
	totalMatching = 0;

	for (size_t i = 1; i <= n; i++) {
		scanf("%zu", &t);
		while (t--) {
			scanf("%zu", &a);
			graph[i].emplace_back(a);
		}
	}

	maximumMatching(n, m);

	size_t tmp = k;
	while (tmp) {
		j += n;
		while (bfs()) {
			for (size_t left = 1; left <= n; left++) {
				if (pairL[left + j] == NIL && dfs(left + j)) {
					totalMatching++;
					goto HELL;
				}
			}
		}
HELL: tmp--;
	}

	printf("%zu", totalMatching);
}