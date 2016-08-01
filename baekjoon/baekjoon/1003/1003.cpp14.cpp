#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> IIP;


IIP dp[41] = {{1, 0}, {0, 1}};

IIP solve(int n) {
	auto &p = dp[n];
	if (p.first + p.second) return p;
	const auto &a = solve(n - 1), &b = solve(n - 2);
	p.first = a.first + b.first;
	p.second = a.second + b.second;
	return p;
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		const auto &ret = solve(n);
		printf("%d %d\n", ret.first, ret.second);
	}
}