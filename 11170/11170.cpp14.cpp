#include <cstdio>

using namespace std;

int solve(int n) {
	if (n < 0) return 0;
	int cnt = 1, prev = 1;
	for (int i = 10; i <= n; i *= 10) {
		if (n % i / prev == 0) cnt += ((n - i) / i) * prev + 1 + n % prev;
		else cnt += (n / i)*prev;
		prev = i;
	}
	return cnt;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", solve(m) - solve(n - 1));
	}
}