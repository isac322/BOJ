#include <cstdio>
#include <algorithm>

using namespace std;

int n, dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
char map[100][101], col;
bool visited[100][100];

void dfs(int r, int c) {
	if (map[r][c] != col || visited[r][c] || r < 0 || c < 0 || r >= n || c >= n) return;

	visited[r][c] = true;

	for (int i = 0; i < 4; i++) dfs(r + dy[i], c + dx[i]);
}

int dfsAll() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				cnt++;
				col = map[i][j];
				dfs(i, j);
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) gets(map[i]);

	printf("%d ", dfsAll());
	for (int i = 0; i < n; i++) {
		fill_n(visited[i], n, false);
		for (int j = 0; j < n; j++) if (map[i][j] == 'R') map[i][j] = 'G';
	}

	printf("%d", dfsAll());
}