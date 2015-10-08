#include <stdio.h>
#define abs(a, b) (a > b ? a - b : b - a)

int main() {
	int n, px, py, x, y, dist[100000] = { 0 }, maxDif, normal, twice, xs[100000], ys[100000], t, tot = 0;
	scanf("%d", &n);
	scanf("%d %d", &px, &py);
	xs[0] = px;
	ys[1] = py;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		xs[i] = x;
		ys[i] = y;
		dist[i] = abs(x, px) + abs(y, py);
		tot += dist[i];
		px = x;
		py = y;
	}
	normal = dist[1] + dist[2];
	twice = abs(xs[0], xs[2]) + abs(ys[0], ys[2]);
	maxDif = normal - twice;
	for (int i = 1; i < n - 2; i++) {
		normal = normal - dist[i] + dist[i + 2];
		twice = abs(xs[i], xs[i + 2]) + abs(ys[i], ys[i + 2]);
		t = normal - twice;
		if (maxDif < t) maxDif = t;
	}
	printf("%d", tot - maxDif);
}