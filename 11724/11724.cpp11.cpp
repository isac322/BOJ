#include <cstdio>

bool visit[1000], map[1000][1000];
int n, m, a, b, cnt;

void dfs(int index) {
	if (visit[index]) return;
	visit[index] = true;
	for (int i = 0; i < n; i++) if (map[index][i]) dfs(i);
}

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		map[a][b] = map[b][a] = true;
	}
	for (int i = 0; i < n; i++) if (!visit[i]) cnt++, dfs(i);
	printf("%d", cnt);
}