#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[41];
int dp[40], len;

int solve(int index) {
	if (index > len) return 0;
	else if (index == len) return 1;
	int &p = dp[index];
	if (p != -1) return p;

	p = 0;
	const char &c = str[index];
	if (c == '0') return p = 0;
	else if (index < len - 1 && (c < '3' || c == '3' && str[index + 1] <= '4')) p += solve(index + 2);
	return p += solve(index + 1);
}

int main() {
	scanf("%s", str);
	len = strlen(str);
	fill_n(dp, 40, -1);
	printf("%d", solve(0));
}