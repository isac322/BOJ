#include <stdio.h>

int main() {
	int t, s = 0, h, m, d;
	scanf("%d", &t);
	while (t--) {
		scanf("%d:%d %d", &h, &m, &d);
		if (h == 6) s += d * 5 + (m + d > 60 ? ((d + m) % 60) * 5 : 0);
		else if (h == 18) s += d * 10 + (m + d > 60 ? ((d + m) % 60) * -5 : 0);
		else s += ((h < 19 && h > 6) ? 10 : 5)*d;
	}
	printf("%d\n", s);
}