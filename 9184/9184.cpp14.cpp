#include <cstdio>

using namespace std;

bool visit[21][21][21];
long long dp[21][21][21];

long long solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
	long long &p = dp[a][b][c];
	if (visit[a][b][c]) return p;
	visit[a][b][c] = true;

	if (a < b && b < c) return p = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
	else return p = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
	int a, b, c;
	while (true) {
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == a && c == a) break;
		else printf("w(%d, %d, %d) = %lld\n", a, b, c, solve(a, b, c));
	}
}