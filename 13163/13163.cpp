#include <cstdio>

int main() {
	int n, t;
	scanf("%d\n", &n);
	while (n--) {
		while ((t = getchar()) != 32);
		printf("god");
		while ((t = getchar()) != 10) if (t != 32) putchar(t);
		puts("");
	}
}