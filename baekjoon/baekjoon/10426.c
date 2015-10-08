#include <stdio.h>

int main() {
	int y, m, d, f = 0, n, t, a[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	scanf("%d-%d-%d %d", &y, &m, &d, &n);
	d += --n;
	while (f != d) {
		f = d, t = a[m];
		if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) t = 29;
		if (d > t)m++, d -= t;
		if (m > 12)m -= 12, y++;
	}
	printf("%d-%02d-%02d", y, m, d);
}