#include <cstdio>

char p[50][5][8];

inline int c(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++) for (int j = 0; j < 7; j++) if (p[a][i][j] != p[b][i][j]) cnt++;
	return cnt;
}

int main() {
	int n, m = 35, a, b;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < 5; j++) gets(p[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			const int &r = c(i, j);
			if (r < m) {
				m = r;
				a = i;
				b = j;
			}
		}
	}
	printf("%d %d", a + 1, b + 1);
}