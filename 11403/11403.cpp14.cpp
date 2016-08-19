#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int map[100][100];

int main() {
	int n, t;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			map[i][j] = t ? 1 : INF;
		}
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = min(map[i][j], map[i][k]+ map[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", map[i][j] == INF ? 0 : 1);
		puts("");
	}
}