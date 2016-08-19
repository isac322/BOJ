#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[100][100], map[100][100];
vector<pair<int, int>> arr;
int n, m, t;

int dfs(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return 1;
	if (visited[y][x]) return 0;
	else if (map[y][x]) {
		visited[y][x] = true;
		arr.emplace_back(y, x);
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
	for (int i = 0; i < n; i++) fill_n(visited[i], m, false);

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
	int prev = 0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t);
			map[i][j] = t ? true : false;
			prev += t;
		}
	}

	for (int cnt = 0;; cnt++) {
		dfsAll();
		
		if (arr.empty()) {
			printf("%d\n%d", cnt, prev);
			return 0;
		}

		for (auto &t : arr) map[t.first][t.second] = false;
		prev = arr.size();
	}
}