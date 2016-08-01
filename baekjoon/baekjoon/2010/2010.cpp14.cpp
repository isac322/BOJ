#include <cstdio>

int main() {
	int s = 1, n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		s += n - 1;
	}
	printf("%d", s);
}