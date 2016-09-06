#include <cstdio>

int main() {
	bool sa;
	int n, t, a, s, m, p;
	scanf("%d", &t);
	while (t--) {
		sa = false;
		p = m = s = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			if (m < a) m = a, p = i, sa = false;
			else if (m == a) sa = true;
			s += a;
		}
		if (sa) puts("no winner");
		else printf("%sority winner %d\n", m * 2 > s ? "maj" : "min", p + 1);
	}
}