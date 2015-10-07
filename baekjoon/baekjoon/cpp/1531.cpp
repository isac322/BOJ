#include <cstdio>

using namespace std;

int main() {
	int mat[101][101] = { 0 };
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x, y, x1, y1;
		scanf("%d%d%d%d", &x, &y, &x1, &y1);
		for (int j = y; j <= y1; ++j) for (int k = x; k <= x1; ++k) mat[j][k]++;
	}
	int cnt = 0;
	for (int j = 1; j < 101; ++j) for (int k = 1; k < 101; ++k) if (mat[j][k] > m) cnt++;
	printf("%d\n", cnt);
}