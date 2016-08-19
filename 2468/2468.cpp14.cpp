#include <cstdio>
#include <algorithm>

using namespace std;

int ans;
char map[100][100], n, m = 100, M, b;
bool visited[100][100];

void dfs(char r, char c) {
	if (r < 0 || c < 0 || r >= n || c >= n || map[r][c] <= b || visited[r][c]) return;
	visited[r][c] = true;

	dfs(r - 1, c);
	dfs(r + 1, c);
	dfs(r, c - 1);
	dfs(r, c + 1);
}

void dfsAll() {
	int cnt = 0;
	for (char i = 0; i < n; i++) for (char j = 0; j < n; j++) if (map[i][j] > b && !visited[i][j]) cnt++, dfs(i, j);
	ans = max(ans, cnt);
}

int main() {
	scanf("%hhd", &n);
	for (char i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%hhd", map[i] + j);
			m = min(m, map[i][j]);
			M = max(M, map[i][j]);
		}
	}
	m = m ? m - 1 : 0;
	for (b = m; b < M; b++) {
		for (int i = 0; i < n; i++) fill_n(visited[i], n, false);
		dfsAll();
	}
	printf("%d", ans);
}