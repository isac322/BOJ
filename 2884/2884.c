#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if (b < 45) {
		if (a == 0) a = 23;
		else a--;
	}
	b = (b + 15) % 60;
	printf("%d %d", a, b);
}