#include <cstdio>
#include <algorithm>

char map[101][101];
short n, sum[101], c, r, w, h;
int main() {
	scanf("%hd", &n);
	for (short i = 1; i <= n; i++) {
		scanf("%hd %hd %hd %hd", &c, &r, &w, &h);
		for (short j = r; j < r + h; j++) std::fill_n(map[j] + c, w, char(i));
	}
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) sum[map[i][j]]++;
	for (int i = 1; i <= n; i++) printf("%hd\n", sum[i]);
}