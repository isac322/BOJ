#include <cstdio>

using namespace std;

int T, M, N, L, G;
int H[101][101], V[101][101], D[101][101][2][201];

int main() {
	int i, j, k, l;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d%d%d", &N, &M, &L, &G);
		for (i = 1; i <= N; i++) for (j = 1; j < M; j++) scanf("%d", H[i] + j);
		for (i = 1; i < N; i++) for (j = 1; j <= M; j++) scanf("%d", V[i] + j);
		for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) for (k = 0; k < 2; k++) for (l = 0; l < 201; l++) D[i][j][k][l] = G + 1;
		D[1][1][0][0] = D[1][1][1][0] = 0;
		int ans = 2e9;
		for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) for (l = 0; l < 201; l++) for (k = 0; k < 2; k++) if (D[i][j][k][l] <= G) {

			if (i == N && j == M) {
				if (ans > l) ans = l;
			}
			if (l < 200 && D[i][j][!k][l + 1] > D[i][j][k][l])
				D[i][j][!k][l + 1] = D[i][j][k][l];
			if (k) {
				if (j < M && D[i][j + 1][k][l] > D[i][j][k][l] + H[i][j])
					D[i][j + 1][k][l] = D[i][j][k][l] + H[i][j];
			}
			else {
				if (i < N && D[i + 1][j][k][l] > D[i][j][k][l] + V[i][j])
					D[i + 1][j][k][l] = D[i][j][k][l] + V[i][j];
			}
		}
		if (ans < 2e9) printf("%d\n", (N + M - 2)*L + ans);
		else puts("-1");
	}
}