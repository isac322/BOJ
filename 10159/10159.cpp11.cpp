#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, p, q;
bool cmp[101][101];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) cmp[i][i] = true;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &p, &q);
		cmp[p][q] = true;
	}
	for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) if (cmp[i][k]) for (int j = 1; j <= n; j++) if (cmp[i][k] && cmp[k][j]) cmp[i][j] = true;

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (cmp[i][j]) cmp[j][i] = true;

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) if (cmp[i][j]) cnt++;
		printf("%d\n", n - cnt);
	}
}