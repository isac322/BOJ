#include <stdio.h>

int main() {
	char month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int n, y = 2014, m = 4, d = 1, i;

	scanf("%d", &n);
	if (1) {
		while (1) {
			if ((((y + 1) % 4 == 0 && (y + 1) % 100 != 0) || (y + 1) % 400 == 0) && n >= 365) {
				if (n > 365) {
					y++;
					n -= 366;
					continue;
				}
			} else if (n >= 365) {
				y++;
				n -= 365;
				continue;
			}
			for (i = m - 1; i < 12 && n >= month[i]; i++, m++) {
				n -= month[i];
				if (i == 1) {
					if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
						if (!n) {
							n = 28;
							goto hell;
						}
						n--;
					}
				}
			}
			if (i != 12) goto hell;
			y++;
			m = 1;
		}
	hell:	printf("%d-%02d-%02d", y, m, d + n);
	}
}