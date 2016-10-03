#include <cstdio>

int main() {
	short map[20][20];
	char trace[20][20] = { 0 }, n;
	scanf("%hhd", &n);
	for (char i = 0; i < n; i++) for (char j = 0; j < n; j++) scanf("%hd", map[i] + j);

	for (char k = 0; k < n; k++) {
		for (char i = 0; i < n; i++) {
			for (char j = 0; j < n; j++) {
				if (i != j && i != k && j != k &&map[i][j] == map[i][k] + map[k][j]) trace[i][j]++;
				else if (map[i][j] > map[i][k] + map[k][j]) return puts("-1"), 0;
			}
		}
	}

	size_t cnt = 0;
	for (char i = 0; i < n; i++) for (char j = i + 1; j < n; j++) if (!trace[i][j]) cnt += map[i][j];
	printf("%zu", cnt);
}