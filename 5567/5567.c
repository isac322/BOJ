#include <stdio.h>

char tree[500][500] = { 0 };
char friefrie[500] = { 0 };

int main() {
	int n, k, a, b, cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		tree[a - 1][b - 1] = 1;
		tree[b - 1][a - 1] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (tree[0][i]) {
			for (int j = 1; j < n; j++) {
				if (tree[i][j]) friefrie[j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) if (tree[0][i] || friefrie[i]) cnt++;
	printf("%d", cnt);
}