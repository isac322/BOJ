#include <stdio.h>

int main() {
	int t, cnt = 0;

	do {
		scanf("%d", &t);
		cnt++;
	} while (getchar() != '\n');
	printf("%d", cnt);
}