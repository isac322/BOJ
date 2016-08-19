#include <cstdio>

int main() {
	bool map[100][100] = { false };
	int n, m, a, b, cnt = 0;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		map[a][b] = map[b][a] = true;
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] |= map[i][k] & map[k][j];
	for (int i = 1; i < n; i++) if (map[0][i]) cnt++;
	printf("%d", cnt);
}