#include <cstdio>
#include <algorithm>

using namespace std;

int n;
const int arr[] = { 1,7,4,2,0,8 };

long long dp[101] = { 0 };

long long solve(int remain) {
	if (remain < 0) return 0x1fffffff;

	long long &ret = dp[remain];
	if (ret != 0x7000000000000000) return ret;

	for (int i = 0; i < 6; i++) {
		ret = min(ret, arr[i] + solve(remain - i - 2) * 10);
	}

	if (ret == 0) ret = 6;

	return ret;
}

void printMax(int n) {
	if (n & 1) {
		putchar('7');
		n -= 3;
	}

	for (; n; n -= 2) putchar('1');
}

int main() {
	int c;
	scanf("%d", &c);

	fill(dp + 1, dp + 101, 0x7000000000000000);

	while (c--) {
		scanf("%d", &n);

		printf("%lld ", solve(n));
		printMax(n);
		puts("");
	}
}