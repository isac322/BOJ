#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef pair<int, int> INTP;
const int &INF = numeric_limits<int>::max();

int e, v;
int b, c;
vector<vector<INTP> > map;

int dijkstra(int src, int last) {
	vector<int> dist(v, INF);
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
	scanf("%d%d", &v, &e);
	map.resize(v);

	for (int i = 0; i < e; i++) {
		int s, d, w;
		scanf("%d%d%d", &s, &d, &w);
		s--, d--;
		map[s].push_back(make_pair(d, w));
		map[d].push_back(make_pair(s, w));
	}
	scanf("%d%d", &b, &c);
	b--, c--;

	int a2b = dijkstra(0, b);
	int a2c = dijkstra(0, c);
	int b2c = dijkstra(b, c);
	int b2d = dijkstra(b, v - 1);
	int c2d = dijkstra(c, v - 1);

	bool p1 = a2b != INF && b2c != INF && c2d != INF, p2 = a2c != INF && b2c != INF && b2d != INF;

	if (p1 && p2) printf("%d", min(a2b + b2c + c2d, a2c + b2c + b2d));
	else if (p1) printf("%d", a2b + b2c + c2d);
	else if (p2) printf("%d", a2c + b2c + b2d);
	else puts("-1");
}