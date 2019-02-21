#include <queue>
#include <limits>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int &INF = numeric_limits<int>::max();

class BipGraph {
	int m, n;

	vector<int> *adj;

	int *pairU, *pairV, *dist;
	int NIL;

public:
	BipGraph(int m, int n);
	void addEdge(int u, int v);

	bool bfs();

	bool dfs(int u);

	int hopcroftKarp();
};

int BipGraph::hopcroftKarp() {
	pairU = new int[m];
	pairV = new int[n];
	dist = new int[m + 1];

	for (int u = 0; u < m; u++) pairU[u] = NIL;
	for (int v = 0; v < n; v++) pairV[v] = NIL;

	int result = 0;

	while (bfs()) {
		for (int u = 0; u < m; u++)
			if (pairU[u] == NIL && dfs(u))
				result++;
	}

	return result;
}

bool BipGraph::bfs() {
	queue<int> Q;

	for (int u = 0; u < m; u++) {
		if (pairU[u] == NIL) {
			dist[u] = 0;
			Q.push(u);
		}
		else dist[u] = INF;
	}

	dist[NIL] = INF;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		if (dist[u] < dist[NIL]) {
			for (auto v : adj[u]) {
				if (dist[pairV[v]] == INF) {
					dist[pairV[v]] = dist[u] + 1;
					Q.push(pairV[v]);
				}
			}
		}
	}

	return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u) {
	if (u != NIL) {
		for (auto v : adj[u]) {
			if (dist[pairV[v]] == dist[u] + 1) {
				if (dfs(pairV[v]) == true) {
					pairV[v] = u;
					pairU[u] = v;
					return true;
				}
			}
		}

		dist[u] = INF;
		return false;
	}
	return true;
}

BipGraph::BipGraph(int m, int n) {
	NIL = this->m = m;
	this->n = n;
	adj = new vector<int>[m];
}

void BipGraph::addEdge(int u, int v) {
	adj[u].push_back(v);
}

int main() {
	int n, m, a, b;
	scanf("%d%d", &n, &m);
	BipGraph graph(n, n);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		graph.addEdge(a, b);
	}
	printf("%d", graph.hopcroftKarp());
}