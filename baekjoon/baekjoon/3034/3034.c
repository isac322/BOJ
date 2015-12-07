#include <stdio.h>
#include <math.h>

int main() {
	int t, n, h, w, q;
	scanf("%d %d %d", &n, &h, &w);
	q = sqrt(h*h + w*w);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (t <= q) puts("DA");
		else puts("NE");
	}
}