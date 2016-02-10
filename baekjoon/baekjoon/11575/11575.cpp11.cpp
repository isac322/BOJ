#include <cstdio>

int main() {
	int t, a, b, c;
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &a, &b);
		while ((c = getchar()) != 10 && c != -1) putchar((a * (c - 'A') + b) % 26 + 'A');
		puts("");
	}
}