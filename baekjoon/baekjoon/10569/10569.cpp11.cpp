#include <cstdio>

int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", 2 + b - a);
	}
}