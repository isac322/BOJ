#include <cstdio>

int n;
unsigned long long t, m = 0x55555555, y;

int main() {
	scanf("%d", &n);
	if (n == 0) {
		puts("0");
		return 0;
	}
	if (n < 0) {
		n = -n;
		m >>= 1;
		y = 1;
	}
	t = n;
	while (t <= m) m >>= 2;
	while (m) {
		unsigned long long d = t - m - 1, f = m + (m << 1) + 1 + y;
		putchar(d&f ? '0' : '1');
		f >>= 1;
		putchar(d&f ? '0' : '1');
		m >>= 2;
	}
	if (y) putchar((t - 1) & 2 ? '0' : '1');
	putchar((t & 1) + '0');
}
