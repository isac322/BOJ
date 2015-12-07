#include <stdio.h>

bool tree[500][500] = { false };
bool friefrie[500] = { false };

int main() {
	int n, k, a, b, cnt = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		tree[a - 1][b - 1] = true;
		tree[b - 1][a - 1] = true;
	}

	for (int i = 1; i < n; i++) {
		if (tree[0][i]) {
			for (int j = 1; j < n; j++) {
				if (tree[i][j]) friefrie[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) if (tree[0][i] | friefrie[i]) cnt++;
	printf("%d", cnt);
}