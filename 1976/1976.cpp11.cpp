#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char dist[200][200];
	int n, m, p, pp;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%hhd", dist[i] + j);
			if (i == j) dist[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) if (dist[i][k] != 0) for (int j = 0; j < n; j++) if (dist[i][k] && dist[k][j]) dist[i][j] = 1;

	scanf("%d", &pp);
	pp--;
	for (int i = 1; i < m; i++) {
		scanf("%d", &p);
		p--;
		if (dist[pp][p] == 0) {
			puts("NO");
			return 0;
		}
		pp = p;
	}
	puts("YES");
}