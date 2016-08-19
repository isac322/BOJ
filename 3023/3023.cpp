#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char card[100][101] = { 0 };
	int n, m, y, x;
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			card[(n << 1) - i - 1][j] = card[(n << 1) - i - 1][(m << 1) - j - 1] = card[i][j] = card[i][(m << 1) - j - 1] = getchar();
		}
		getchar();
	}
	scanf("%d %d", &y, &x);
	card[y - 1][x - 1] = card[y - 1][x - 1] == '.' ? '#' : '.';
	for (int i = 0; i < n << 1; i++) puts(card[i]);
}