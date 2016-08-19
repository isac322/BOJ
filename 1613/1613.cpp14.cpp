#include <cstdio>

int main() {
	bool map[400][400] = { false };
	int n, k, a, b, s;
	scanf("%d%d", &n, &k);
	while (k--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		map[a][b] = true;
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) map[i][j] |= map[i][k] & map[k][j];
	scanf("%d", &s);
	while (s--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		puts(map[a][b] ? "-1" : map[b][a] ? "1" : "0");
	}
}