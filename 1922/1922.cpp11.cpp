#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

typedef pair<int, int> PAIR;

const int &INF = numeric_limits<int>::max();

vector<PAIR> G[1000];

bool selected[1000];
int dist[1000];
int v, e;

int prim() {
	size_t cnt = v - 1;

	fill_n(dist, v, INF);

	priority_queue<PAIR, vector<PAIR>, greater<PAIR> > que;

	int re = 0;
	dist[0] = 0;
	selected[0] = true;
	que.emplace(-1, 0);

	while (cnt != 0) {
		PAIR t = que.top();
		que.pop();

		int here = t.second;

		if (t.first != -1) {
			if (selected[here]) continue;

			re += t.first;

			selected[here] = true;
			cnt--;
		}

		for (auto i : G[here]) {
			const int &there = i.second;
			const int &weight = i.first;

			if (!selected[there] && dist[there] > weight) {
				dist[there] = weight;

				que.emplace(weight, there);
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
		G[a].emplace_back(c, b);
		G[b].emplace_back(c, a);
	}

	printf("%d", prim());
}