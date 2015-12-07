#include <stdio.h>

int main() {
	int a = 1, b = 0, t, i;
	scanf("%d", &i);
	while (i--) {
		t = b;
		b += a;
		a = t;
	}
	printf("%d %d", a, b);
}