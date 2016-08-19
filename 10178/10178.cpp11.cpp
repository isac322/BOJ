#include <cstdio>

int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", a / b, a%b);
	}
}