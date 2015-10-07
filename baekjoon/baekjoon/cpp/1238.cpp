#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair<int, int> INTP;
const int &INF = numeric_limits<int>::max();

int e, v, x;
vector<vector<INTP> > map;

vector<int> dist;
int dijkstra(int src, int last) {
	fill(dist.begin(), dist.end(), INF);
	dist[src] = 0;

	priority_queue <INTP, vector<INTP>, greater<INTP> > que;
	que.push(make_pair(0, src));

	while (que.size()) {
		const int here = que.top().second;
		const int cost = que.top().first;
		que.pop();
		if (here == last) break;

		const vector<INTP>::iterator &end = map[here].end();
		for (vector<INTP>::iterator i = map[here].begin(); i != end; i++) {
			if (dist[i->first] > dist[here] + i->second) {
				dist[i->first] = dist[here] + i->second;
				que.push(make_pair(dist[i->first], i->first));
			}
		}
	}

	return dist[last];
}

int main() {
	scanf("%d%d%d", &v, &e, &x);
	x--;
	map.resize(v);
	dist.resize(v);

	for (int i = 0; i < e; i++) {
		int s, d, w;
		scanf("%d%d%d", &s, &d, &w);
		s--, d--;
		map[s].push_back(make_pair(d, w));
	}

	int ret = 0;
	for (int i = 0; i < v; i++) ret = max(ret, dijkstra(i, x) + dijkstra(x, i));
	printf("%d", ret);
}