#include <cstdio>
#include <algorithm>

using namespace std;

short n, students[1000];
int dp[1000][1000];

int solve(short left, short right) {
	int &p = dp[left][right];
	if (p != -1) return p;
	if (left >= right) return p = 0;

	short m = students[left], M = students[left];
	for (short i = left; i <= right; i++) {
		m = min(m, students[i]);
		M = max(M, students[i]);

		p = max(p, M - m + solve(i + 1, right));
	}

	return p;
}

int main() {
	scanf("%hd", &n);
	for (short i = 0; i < n; i++) {
		fill_n(dp[i], n, -1);
		scanf("%hd", students + i);
	}
	printf("%d", solve(0, n - 1));
}