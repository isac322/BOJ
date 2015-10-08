#include <stdio.h>
#include <memory.h>

int c;
char mat[3072][6145];

void paint(int c, int r) {
	int l = c - (r >> 1);
	for (int i = 0; i < (r >> 1); i++) memcpy(mat[(r >> 1) + i] + l - i, mat[i] + c - i, sizeof(char) * ((i << 1) + 1));
	l = c + (r >> 1);
	for (int i = 0; i < (r >> 1); i++) memcpy(mat[(r >> 1) + i] + l - i, mat[i] + c - i, sizeof(char) * ((i << 1) + 1));
}

int main() {
	int n;
	scanf("%d", &n);
	c = n  - 1;
	for (int i = 0; i < n; i++) memset(mat[i], ' ', sizeof(char)*(n << 1));
	mat[0][c] = mat[1][c - 1] = mat[1][c + 1] = mat[2][c - 2] = mat[2][c - 1] = mat[2][c] = mat[2][c + 1] = mat[2][c + 2] = '*';
	for (int i = 3; i <= n; i <<= 1) paint(c, i);
	for (int i = 0; i < n; i++) puts(mat[i]);
}