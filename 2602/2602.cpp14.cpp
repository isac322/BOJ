#include <cstdio>
#include <algorithm>

using namespace std;

int dp[2][20][100];
char t[21], a[101], b[101], c;
int tn, an, bn;

int solve(bool c, int ti, int bi) {
	if (bi >= bn) return 0;
	int &p = dp[c ? 1 : 0][ti][bi];
	if (p != -1) return p;

	if (ti == tn - 1) return p = 1;

	p = 0;
	char *next = c ? a : b, *here = c ? b : a;
	char n = t[ti + 1];
	for (int i = bi + 1; i < an; i++) {
		if (next[i] == n) p += solve(!c, ti + 1, i);
	}
	return p;
}

int main() {
	while ((c = getchar()) != 10) t[tn++] = c;
	while ((c = getchar()) != 10) a[an++] = c;
	for (; bn < an; bn++) b[bn] = getchar();
	for (int i = 0; i < tn; i++) {
		fill_n(dp[0][i], an, -1);
		fill_n(dp[1][i], an, -1);
	}
	int p = 0;
	for (int i = 0; i < an; i++) if (a[i] == t[0]) p += solve(false, 0, i);
	for (int i = 0; i < bn; i++) if (b[i] == t[0]) p += solve(true, 0, i);
	printf("%d", p);
}