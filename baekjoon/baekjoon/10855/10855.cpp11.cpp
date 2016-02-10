#include <cstdio>

int main() {
	int n, p, c;
	scanf("%d%d", &n, &p);
	for (int i = 1; i < n; i++) {
		scanf("%d", &c);
		if (p > c) {
			puts("no");
			return 0;
		}
		p = c;
	}
	puts("yes");
}