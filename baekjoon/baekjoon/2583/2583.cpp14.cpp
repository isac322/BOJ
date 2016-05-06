#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool map[100][100], visited[100][100];
int m, n, k;

int dfs(int y, int x) {
	if (x < 0 || y < 0 || x >= n || y >= m || map[y][x] || visited[y][x]) return 0;
	visited[y][x] = true;

	int re = 1;
	re += dfs(y - 1, x);
	re += dfs(y + 1, x);
	re += dfs(y, x - 1);
	re += dfs(y, x + 1);

	return re;
}

int main() {
	scanf("%d %d %d", &m, &n, &k);

	int x1, x2, y1, y2;
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int j = y1; j < y2; j++) fill(map[j] + x1, map[j] + x2, true);
	}

	vector<int> arr;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			const int &p = dfs(y, x);
			if (p) arr.emplace_back(p);
		}
	}
	printf("%zd\n", arr.size());
	sort(arr.begin(), arr.end());
	for (int p : arr) printf("%d ", p);
}