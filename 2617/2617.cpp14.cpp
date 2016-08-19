#include <cstdio>

int main() {
	int n, m, a, b;
	bool inMap[500][500] = { false }, outMap[500][500] = { false };
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &a, &b);
		a--, b--;
		inMap[a][b] = outMap[b][a] = true;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				inMap[i][j] |= inMap[i][k] & inMap[k][j];
				outMap[i][j] |= outMap[i][k] & outMap[k][j];
			}
		}
	}

	int inCnt, outCnt, sum = 0;
	for (int i = 0; i < n; i++) {
		inCnt = outCnt = 0;
		for (int j = 0; j < n; j++) {
			if (inMap[i][j]) inCnt++;
			if (outMap[i][j]) outCnt++;
		}
		if (inCnt > n / 2 || outCnt > n / 2) sum++;
	}
	printf("%d", sum);
}