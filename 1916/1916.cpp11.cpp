#include <queue>
#include <cstdio>
#include <functional>

using namespace std;
const int INF = 2000000000;
typedef pair<int, int> PII;

int main() {
	int N, M, s, t;
	scanf("%d%d", &N, &M);
	vector<vector<PII>> edges(N);

	for (int i = 0; i < M; i++) {
		int src, vertex, dist;
		scanf("%d%d%d", &src, &vertex, &dist);
		src--, vertex--;
		edges[src].emplace_back(dist, vertex);
	}
	scanf("%d%d", &s, &t);
	s--, t--;

	priority_queue<PII, vector<PII>, greater<PII>> Q;
	vector<int> dist(N, INF);
	Q.emplace(0, s);
	dist[s] = 0;
	while (!Q.empty()) {
		PII p = Q.top();
		if (p.second == t) break;
		Q.pop();

		int here = p.second;
		for (const auto it : edges[here]) {
			if (dist[here] + it.first < dist[it.second]) {
				dist[it.second] = dist[here] + it.first;
				Q.emplace(dist[it.second], it.second);
			}
		}
	}

	printf("%d\n", dist[t]);
}