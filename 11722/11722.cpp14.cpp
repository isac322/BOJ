#include <cstdio>
#include <algorithm>

using namespace std;

short n, dp[1000], arr[1000], m = 0;

short solve(short index) {
	short &p = dp[index];
	if (p) return p;

	short t;
	for (short i = index + 1; i < n; i++) {
		t = solve(i);
		if (arr[i] < arr[index]) p = max(p, t);
	}

	m = max(m, ++p);
	return p;
}

int main() {
	scanf("%hd", &n);
	for (int i = 0; i < n; i++) scanf("%hd", arr + i);
	solve(0);
	printf("%hd", m);
}