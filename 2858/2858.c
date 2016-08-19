#include <stdio.h>

int main() {
	int R, B;
	int i;

	scanf("%d %d", &R, &B);

	if (R && !B) {
		puts("1 1");
		return 0;
	}
	for (i = 1; i <= B / 2; i++) {
		if (!(B%i)) {
			if ((((B / i) + 2) * 2 + i * 2) == R) break;
		}
	}

	printf("%d %d", B / i + 2, i + 2);
}