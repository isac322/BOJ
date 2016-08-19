#include <cstdio>
#include <algorithm>

using namespace std;

int solve2(long long, long long);

int solve1(long long m, long long t) {
	if (m == 0) return 0;
	return solve2(m%t, t / 10LL) + m / t;
}

int solve2(long long m, long long t) {
	if (m == 0) return 0;
	int q = solve1(m%t, t / 10LL) + m / t;
	t /= 10LL;
	int i = 1;
	for (long long d = t * 25LL; d <= m; d += t * 25LL, i++) {
		q = min(q, solve1((m - d) % (t * 10LL), t) + i + int((m - d) / (t * 10LL)));
	}
	return q;
}

int main() {
	int t;
	long long n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		int cnt = 0;
		long long t = 1;
		for (long long q = n; q > 0LL; cnt++) {
			q /= 10LL;
			t *= 10LL;
		}
		t /= 10LL;
		printf("%d\n", cnt & 1 ? solve1(n, t) : solve2(n, t));
	}
}