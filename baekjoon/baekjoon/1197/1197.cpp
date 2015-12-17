#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

typedef pair<int, int> PAIR;

const int &INF = numeric_limits<int>::max();

vector<PAIR> G[10000];

bool selected[10000];
int dist[10000];
int v, e;

int prim() {
	size_t cnt = v - 1;

	fill_n(dist, v, INF);

	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > que;

	int re = 0;
	dist[0] = 0;
	selected[0] = true;
	que.push(make_pair(-1, 0));

	while (cnt != 0) {
		PAIR t = que.top();
		que.pop();

		int here = t.second;

		if (here != 0) {
			if (selected[here]) continue;

			re += t.first;

			selected[here] = true;
			cnt--;
		}

		for (vector<PAIR>::iterator i = G[here].begin(); i != G[here].end(); i++) {
			const int &there = i->second;
			const int &weight = i->first;

			if (!selected[there] && dist[there] > weight) {
				dist[there] = weight;

				que.push(make_pair(weight, there));
			}
		}
	}

	return re;
}

int main() {
	int a, b, c;
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		G[a].push_back(make_pair(c, b));
		G[b].push_back(make_pair(c, a));
	}

	printf("%d", prim());
}