#include <stdio.h>

int main() {
	long long a, b, y, t, z;
	while (~scanf("%lld %lld", &a, &b)) {
		t = 99 - b * 100 / a;
		if (t < 1) {
			puts("-1");
			continue;
		}
		z = 100 * (a - b);
		printf("%lld\n", z / t - a + (z%t ? 1 : 0));
	}
}