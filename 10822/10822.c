#include <stdio.h>

int main() {
	int t, sum = 0;

	do {
		scanf("%d", &t);
		sum += t;
	} while (getchar() != '\n');
	printf("%d", sum);
}