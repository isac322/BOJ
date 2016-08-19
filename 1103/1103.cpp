#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[50][50];
char mat[50][51];
char n, m;
short dp[50][50];

short solve(char r, char c) {
	if (r < 0 || r >= n || c < 0 || c >= m) return 0;

	if (visited[r][c]) return -1;
	short &p = dp[r][c];

	if (p != -2) return p;

	visited[r][c] = true;
	const char &ch = mat[r][c];
	const char v = ch - '0';

	p = 0;
	if (ch == 'H') {
		visited[r][c] = false;
		return p;
	}

	short ret = solve(r + v, c);
	if (ret == -1) {
		visited[r][c] = false;
		return p = -1;
	}
	p = max(p, ret);

	ret = solve(r - v, c);
	if (ret == -1) {
		visited[r][c] = false;
		return p = -1;
	}
	p = max(p, ret);

	ret = solve(r, c + v);
	if (ret == -1) {
		visited[r][c] = false;
		return p = -1;
	}
	p = max(p, ret);

	ret = solve(r, c - v);
	if (ret == -1) {
		visited[r][c] = false;
		return p = -1;
	}
	p = max(p, ret);

	visited[r][c] = false;
	return ++p;
}

int main() {
	scanf("%hhd %hhd\n", &n, &m);

	for (char i = 0; i < n; i++) {
		fill(dp[i], dp[i] + m, -2);
		gets(mat[i]);
	}

	printf("%hd\n", solve(0, 0));
}