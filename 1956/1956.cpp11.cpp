#include <cstdio>
#include <algorithm>

using namespace std;

int map[400][400];

int main() {
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		fill_n(map[i], n, 987654321);
		map[i][i] = 0;
	}
	while (m--) {
		scanf("%d %d %d", &a, &b, &c);
		a--, b--;
		map[a][b] = c;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (map[i][k] != 987654321) {
				for (int j = 0; j < n; j++) map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}

	int q = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) q = min(q, map[i][j] + map[j][i]);
		}
	}

	printf("%d", q == 987654321 ? -1 : q);
}