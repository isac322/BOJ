#include <stdio.h>

int main() {
	int c;
	scanf("%d", &c);

	for (int i = 1; i <= c; i++) {
		size_t a, b, c, d, e, f, g;
		scanf("%u %u %u %u %u %u", &a, &b, &c, &d, &e, &f);
		size_t sum1 = a * 1 + b * 2 + c * 3 + d * 3 + e * 4 + f * 10;
		scanf("%u %u %u %u %u %u %u", &a, &b, &c, &d, &e, &f, &g);
		size_t sum2 = a * 1 + b * 2 + c * 2 + d * 2 + e * 3 + f * 5 + g * 10;

		if (sum2 == sum1) {
			printf("Battle %d: No victor on this battle field\n", i);
		}
		else if (sum1 < sum2) {
			printf("Battle %d: Evil eradicates all trace of Good\n", i);
		}
		else {
			printf("Battle %d: Good triumphs over Evil\n", i);
		}
	}
}