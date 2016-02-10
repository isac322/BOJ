#include <cstdio>
#include <cmath>

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++) {
		long long l, h;
		scanf("%lld %lld", &h, &l);
		long long sum = 1LL;

		double t = log2(l);
		int tmp = int(t);
		sum = (1LL << (tmp + 1)) - 1LL;
		if (double(tmp) != t) {
			sum += l;
			tmp++;
		}

		sum += l*(h - tmp);
		printf("Case %d: %lld\n", c, sum);
	}
}