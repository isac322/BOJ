#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair<int, int> INTP;
const int &INF = numeric_limits<int>::max();

int main() {
	int e, v, start;
	scanf("%d%d%d", &e, &v, &start);
	start--;
	vector<vector<INTP>> map(e);
	vector<int> dist(e, INF);
	dist[start] = 0;

	for (int i = 0; i < v; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		map[u].emplace_back(v, w);
	}

	priority_queue <INTP, vector<INTP>, greater<INTP>> que;
	que.emplace(0, start);

	while (que.size()) {
		const int here = que.top().second;
		que.pop();

		for (auto &i : map[here]) {
			if (dist[i.first] > dist[here] + i.second) {
				dist[i.first] = dist[here] + i.second;
				que.emplace(dist[i.first], i.first);
			}
		}
	}

	for (int d : dist) {
		if (d != INF) printf("%d\n", d);
		else puts("INF");
	}
}