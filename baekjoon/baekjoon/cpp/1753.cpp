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
	vector<vector<INTP> > map(e);
	vector<int> dist(e, INF);
	dist[start] = 0;

	for (int i = 0; i < v; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		map[u].push_back(make_pair(v, w));
	}

	priority_queue <INTP, vector<INTP>, greater<INTP> > que;
	que.push(make_pair(0, start));

	while (que.size()) {
		const int here = que.top().second;
		const int cost = que.top().first;
		que.pop();

		for (vector<INTP>::iterator i = map[here].begin(); i != map[here].end(); i++) {
			if (dist[i->first] > dist[here] + i->second) {
				dist[i->first] = dist[here] + i->second;
				que.push(make_pair(dist[i->first], i->first));
			}
		}
	}

	for (int i = 0; i < e; i++) {
		if (dist[i] != INF) printf("%d\n", dist[i]);
		else puts("INF");
	}
}