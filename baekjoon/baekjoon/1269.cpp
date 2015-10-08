#include <stdio.h>
#include <algorithm>

int main() {
	int a[200000], b[200000];
	int n, m, t, i, ai = 0, bi = 0, cnt = 0, c, d;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	for (i = 0; i < m; i++) scanf("%d", b + i);
	std::sort(a, a + n);
	std::sort(b, b + m);
	while (ai < n && bi < m) {
		c = a[ai];
		d = b[bi];
		if (c == d) {
			cnt++;
			ai++;
			bi++;
		} else if (c < d) ai++;
		else bi++;
	}
	printf("%d", n + m - (cnt << 1));
}