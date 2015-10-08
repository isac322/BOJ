#include <stdio.h>

int main() {
	long long a, b, i;
	scanf("%lld%lld", &a, &b);
	if (a > b) {
		i = b;
		b = a;
		a = i;
	}
	if (a == b) {
		puts("0");
		return 0;
	}
	printf("%d\n", b - a - 1);
	for (i = a + 1; i < b; i++) printf("%lld ", i);
}