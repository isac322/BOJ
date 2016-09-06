#include <stdio.h>
#define abs(a, b) (a > b ? a - b : b - a)

int main() {
	int n, ppx, ppy, px, py, x, y, dist, maxDif, normal, twice, pdist, tot, t, ppdist;
	scanf("%d", &n);
	scanf("%d %d", &x, &y);
	scanf("%d %d", &ppx, &ppy);
	ppdist = abs(ppx, x) + abs(ppy, y);
	scanf("%d %d", &px, &py);
	pdist = abs(px, ppx) + abs(py, ppy);
	tot = normal = ppdist + pdist;
	twice = abs(px, x) + abs(py, y);
	maxDif = normal - twice;
	for (int i = 3; i < n; i++) {
		scanf("%d %d", &x, &y);
		dist = abs(x, px) + abs(y, py);
		tot += dist;
		normal = normal - ppdist + dist;
		twice = abs(ppx, x) + abs(ppy, y);
		t = normal - twice;
		if (maxDif < t) maxDif = t;
		ppdist = pdist;
		pdist = dist;
		ppx = px;
		ppy = py;
		px = x;
		py = y;
	}
	printf("%d", tot - maxDif);
}