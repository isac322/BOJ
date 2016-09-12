#include <tuple>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

char cost[125][125];
short dist[125][125];
typedef tuple<short, char, char> TUP;
priority_queue<TUP, vector<TUP>, greater<TUP>> que;

int main() {
	int t = 1;
    short d;
	char y, x;
	while (true) {
		int n;
		scanf("%d", &n);
		if (!n) break;

		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%hhd", cost[i] + j);

		que.emplace(cost[0][0], 0, 0);

		for (int i = 0; i < n; i++) fill_n(dist[i], n, 30000);
		dist[0][0] = cost[0][0];

		while (!que.empty()) {
			d = get<0>(que.top());
			y = get<1>(que.top());
			x = get<2>(que.top());
			que.pop();
			if (y == n - 1 && y == x) break;

			if (y + 1 < n && dist[y + 1][x] > d + cost[y + 1][x]) {
				dist[y + 1][x] = d + cost[y + 1][x];
				que.emplace(dist[y + 1][x], y + 1, x);
			}
			if (y > 0 && dist[y - 1][x] > d + cost[y - 1][x]) {
				dist[y - 1][x] = d + cost[y - 1][x];
				que.emplace(dist[y - 1][x], y - 1, x);
			}
			if (x + 1 < n && dist[y][x + 1] > d + cost[y][x + 1]) {
				dist[y][x + 1] = d + cost[y][x + 1];
				que.emplace(dist[y][x + 1], y, x + 1);
			}
			if (x > 0 && dist[y][x - 1] > d + cost[y][x - 1]) {
				dist[y][x - 1] = d + cost[y][x - 1];
				que.emplace(dist[y][x - 1], y, x - 1);
			}
		}
		while (!que.empty()) que.pop();

		printf("Problem %d: %hd\n", t, dist[n - 1][n - 1]);
		t++;
	}
}