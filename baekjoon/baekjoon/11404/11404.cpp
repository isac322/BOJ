#include <cstdio>
#include <algorithm>

using namespace std;

int map[100][100];

int main() {
	int n, m, a, b, c;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 987654321);
		map[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		map[a][b] = min(map[a][b], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", map[i][j] == 987654321 ? 0 : map[i][j]);
		puts("");
	}
}