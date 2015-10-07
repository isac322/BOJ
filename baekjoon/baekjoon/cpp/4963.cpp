#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
bool map[50][50];
int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool visited[50][50];

bool dfs(int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= m) return false;

	if (visited[r][c] || map[r][c] == 0) return false;
	visited[r][c] = true;

	bool check = false;
	for (int i = 0; i < 8; i++) {
		if (map[r + dx[i]][c + dy[i]]) {
			check |= dfs(r + dx[i], c + dy[i]);
		}
	}

	return true;
}

int main() {
	while (true) {
		scanf("%d%d", &m, &n);
		if (n == 0 && m == 0) break;

		int t;
		for (int i = 0; i < n; i++) {
			fill_n(visited[i], m, false);
			for (int j = 0; j < m; j++) {
				scanf("%d", &t);
				map[i][j] = t ? true : false;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dfs(i, j)) cnt++;
			}
		}

		printf("%d\n", cnt);
	}
}