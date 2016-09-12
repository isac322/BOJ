#include <cstdio>
#include <algorithm>

using namespace std;

#define M 1'000'000'007

long long f = 1, kf;
int n, k, t, i = 2;

inline int solve(long long n, int m) {
	long long ret = 1;
	while (m) {
		if (m & 1) ret = (ret * n) % M;
		n = (n * n) % M;
		m >>= 1;
	}
	return int(ret);
}

int main() {
	scanf("%d%d", &n, &k);

	t = min(n - k, k);
	for (; i <= t; i++) f = (f * i) % M;
	kf = f;
	t = max(n - k, k);
	for (; i <= t; i++) f = (f * i) % M;
	kf = (kf * f) % M;
	for (; i <= n; i++) f = (f * i) % M;
	printf("%lld", (f*solve(kf, M - 2)) % M);
}