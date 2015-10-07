#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p%q);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int N = gcd(a, b);
	int i = 1;
	for (; i*i < N; i++) {
		if (N % i == 0) {
			int t = N / i;
			printf("%d %d %d\n", i, a / i, b / i);
			printf("%d %d %d\n", t, a / t, b / t);
		}
	}

	if (i*i == N) printf("%d %d %d", i, a / i, b / i);
}