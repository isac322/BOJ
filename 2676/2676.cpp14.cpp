#include <cstdio>

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		if (n < 0 || m < 0 || m > n) puts("0");
		else if (!m || n == m) puts("1");
		else {
			int dif = m - 1;
			if (m > n / 2) m = n - 1 - m;
			for (int i = 0, c = n - 3; i < dif; i++, c -= 2) n += c;
			printf("%d\n", n);
		}
	}
}