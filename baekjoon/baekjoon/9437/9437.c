#include <stdio.h>

int main() {
	int n, p, a, b, c;
	while (scanf("%d", &n), n) {
		scanf("%d", &p);

		if (n / 2 >= p) {
			if (p & 1) {
				a = p + 1;
				b = n - p;
				c = b + 1;
			} else {
				a = p - 1;
				b = n - p + 1;
				c = b + 1;
			}
		} else {
			if (p & 1) {
				c = p + 1;
				b = n - p + 1;
				a = b - 1;
			} else {
				c = p - 1;
				b = n - c + 1;
				a = b - 1;
			}
		}
		printf("%d %d %d\n", a, b, c);
	}
}