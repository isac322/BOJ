#include <stdio.h>

int main() {
	int t;
	scanf("%d\n", &t);

	for (int i = 1; i <= t; i++) {
		char t;
		printf("String #%d\n", i);
		while ((t = getchar()) != 10) {
			putchar((t - 'A' + 1) % 26 + 'A');
		}
		puts("\n");
	}
}