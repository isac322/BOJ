#include <cstdio>

int main() {
	int n, l = 1, r, s = 0, t;
	scanf("%d %d%d", &n, &r, &t);
	while (t--) {
		scanf("%d", &n);
		if (n < l) {
			s += l - n;
			r -= l - n;
			l = n;
		}
		else if (r < n) {
			s += n - r;
			l += n - r;
			r = n;
		}
	}
	printf("%d", s);
}