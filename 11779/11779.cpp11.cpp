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
	vector<PII> dist(N, make_pair(INF, 0));
	Q.emplace(0, s);
	dist[s] = make_pair(0, -1);
	while (!Q.empty()) {
		PII p = Q.top();
		if (p.second == t) break;
		Q.pop();

		int here = p.second;
		for (const auto it : edges[here]) {
			const auto &weight = it.first, &there = it.second;

			if (dist[here].first + weight < dist[there].first) {
				dist[there].first = dist[here].first + weight;
				dist[there].second = here;
				Q.emplace(dist[there].first, there);
			}
		}
	}

	printf("%d\n", dist[t].first);

	vector<int> re = { t };
	int cnt = 1;
	auto p = dist[t];
	do {
		re.emplace_back(p.second);
		p = dist[p.second];
		cnt++;
	} while (p.second != -1);
	printf("%d\n", cnt);
	for (auto t = re.rbegin(); t != re.rend(); t++) printf("%d ", *t + 1);
}