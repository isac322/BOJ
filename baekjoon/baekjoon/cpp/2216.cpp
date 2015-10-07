#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits>

using namespace std;

int a, b, c;
char str1[3002], str2[3002];
int len1, len2;

long long dp[3001][3001];

long long solve(short Li, short Ri) {
	long long &p = dp[Li][Ri];
	if (p != -1) return p;

	if (Li == len1 && Ri == len2) {
		return p = 0;
	}

	long long ret = numeric_limits<long long>::min();

	if (Li != len1) {
		ret = max(ret, solve(Li + 1, Ri) + b);
	}

	if (Ri != len2) {
		ret = max(ret, solve(Li, Ri + 1) + b);
	}

	if (Li != len1 && Ri != len2) {
		if (str1[Li] == str2[Ri]) {
			ret = max(ret, solve(Li + 1, Ri + 1) + a);
		}
		else {
			ret = max(ret, solve(Li + 1, Ri + 1) + c);
		}
	}

	return p = ret;
}

int main() {
	scanf("%d %d %d\n", &a, &b, &c);

	gets(str1);
	gets(str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 0; i <= len1; i++) fill(dp[i], dp[i] + len2 + 1, -1);

	printf("%lld\n", solve(0, 0));
}