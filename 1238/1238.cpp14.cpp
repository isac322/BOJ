#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, x, a, b, c, map[1000][1000];
int main() {
	scanf("%d%d%d", &n, &m, &x);
	x--;
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 987654321);
		map[i][i] = 0;
	}
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		map[a][b] = c;
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) if (map[i][k] != 987654321) for (int j = 0; j < n; j++) map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	for (int i = 0; i < n; i++) m = max(m, map[i][x] + map[x][i]);
	printf("%d", m);
}