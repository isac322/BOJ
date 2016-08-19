#include <cstdio>
#include <algorithm>

using namespace std;

int map[100][100];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 987654321);
		map[i][i] = 0;
	}
	while (m--) {
		scanf("%d %d", &a, &b);
		a--, b--;
		map[b][a] = map[a][b] = 1;
	}

	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) if (map[i][k] != 987654321) for (int j = 0; j < n; j++) map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

	int q = 987654321, index = 0;
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < n; j++) t += map[i][j];
		if (q > t) {
			q = t;
			index = i;
		}
	}
	printf("%d", index + 1);
}