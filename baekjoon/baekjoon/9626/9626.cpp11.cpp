#include <cstdio>

char str[20][21];
int main() {
	int n, m, u, l, r, d;
	scanf("%d %d\n%d %d %d %d\n", &m, &n, &u, &l, &r, &d);
	for (int i = 0; i < u + d + m; i++) for (int j = 0; j < l + r + n; j++) str[i][j] = (i + j) & 1 ? '.' : '#';
	for (int i = u; i < u + m; i++, getchar()) for (int j = l; j < l + n; j++) str[i][j] = getchar();
	for (int i = 0; i < u + d + m; i++) puts(str[i]);
}