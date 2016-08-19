#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

char cnt[100][100];
bool visited[100][100], map[100][100];
vector<pair<int, int>> arr;
int n, m, t;

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return 1;
	if (visited[y][x]) return 0;
	else if (map[y][x]) {
		arr.emplace_back(y, x);
		cnt[y][x]++;
		return 1;
	}

	visited[y][x] = true;

	int ret = 0;
	ret += dfs(y - 1, x);
	ret += dfs(y + 1, x);
	ret += dfs(y, x + 1);
	ret += dfs(y, x - 1);

	return ret;
}

void dfsAll() {
	arr.clear();
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], m, false);
		fill_n(cnt[i], m, 0);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!map[i][j]) {
				if (dfs(i, j) > arr.size()) return;
				else arr.clear();
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			map[i][j] = t ? true : false;
		}
	}

	for (int day = 0;; day++) {
		dfsAll();

		if (arr.empty()) {
			printf("%d", day);
			return 0;
		}

		for (auto &t : arr) if (cnt[t.first][t.second] >= 2) map[t.first][t.second] = false;
	}
}