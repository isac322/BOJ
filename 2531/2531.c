#include <stdio.h>

int main() {
	int a[30000], b[3001] = { 0 }, c, d, k, e, f, g, h, i = 0;

	scanf("%d %d %d %d", &c, &d, &k, &e);
	g = k;
	for (; i < c; i++) {
		scanf("%d", a + i);
		if (i < k) if (b[a[i]]++) g--;
	}

	f = g + (b[e] ? 0 : 1);
	for (i = 0; i < c; i++) {
		if (!--b[a[i%c]]) g--;
		if (!b[a[(i + k)%c]]++) g++;
		h = b[e] ? 0 : 1;
		if (f < g + h) f = g + h;
	}
	printf("%d", f);
}