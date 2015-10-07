#include <cstdio>
#include <algorithm>

using namespace std;

#define T true
#define F false
#define M 1234567

const bool map[][10] = {
	{ F,F,F,F,F,F,F,T,F,F },
	{ F,F,T,F,T,F,F,F,F,F },
	{ F,T,F,T,F,T,F,F,F,F },
	{ F,F,T,F,F,F,T,F,F,F },
	{ F,T,F,F,F,T,F,T,F,F },
	{ F,F,T,F,T,F,T,F,T,F },
	{ F,F,F,T,F,T,F,F,F,T },
	{ T,F,F,F,T,F,F,F,T,F },
	{ F,F,F,F,F,T,F,T,F,T },
	{ F,F,F,F,F,F,T,F,T,F },
};

int dp[1001][10];

int solve2(int left, int start) {
	int &ret = dp[left][start];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 10; i++) {
		if (map[start][i]) ret += solve2(left - 1, i);
	}

	return ret %= M;
}

int solve(int num) {
	int ret = 0;
	for (int i = 0; i < 10; i++) ret += solve2(num, i);

	return ret % M;
}

int main() {
	int t, n;
	scanf("%d", &t);
	fill_n(dp[1], 10, 1);
	for (int i = 2; i < 1001; i++) fill_n(dp[i], 10, -1);

	while (t--) {
		scanf("%d", &n);
		printf("%d\n", solve(n));
	}
}