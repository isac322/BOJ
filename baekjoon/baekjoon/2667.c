#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *) a - *(int *) b; }

int n, cnt = 0, arr[300] = { 0 }, c;
char map[25][26] = { "" };

void dfs(int i, int j) {
	map[i][j] = '0';
	c++;
	if (i > 0 && map[i - 1][j] == '1') dfs(i - 1, j);
	if (j > 0 && map[i][j - 1] == '1') dfs(i, j - 1);
	if (i < n - 1 && map[i + 1][j] == '1') dfs(i + 1, j);
	if (j < n - 1 && map[i][j + 1] == '1') dfs(i, j + 1);
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) gets(map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1') {
				c = 0;
				dfs(i, j);
				arr[cnt++] = c;
			}
		}
	}
	printf("%d\n", cnt);
	qsort(arr, cnt, sizeof(int), cmp);
	for (int i = 0; i < cnt; i++) printf("%d\n", arr[i]);
}