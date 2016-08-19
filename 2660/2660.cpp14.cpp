#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b, map[50][50], INF = 987654321;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, INF);
		map[i][i] = 0;
	}
	while (true) {
		scanf("%d%d", &a, &b);
		if (a == -1 && a == b) break;
		a--, b--;
		map[b][a] = map[a][b] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (map[i][k] != INF) for (int j = 0; j < n; j++) map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
		}
	}
	vector<int> candidates;
	int m = n, h;
	for (int i = 0; i < n; i++) {
		h = 0;
		for (int j = 0; j < n; j++) if (map[i][j] != INF) h = max(h, map[i][j]);
		if (m > h) {
			m = h;
			candidates.clear();
			candidates.emplace_back(i);
		}
		else if (m == h) candidates.emplace_back(i);
	}
	printf("%d %zd\n", m, candidates.size());
	for (auto &v : candidates) printf("%d ", v + 1);
}