#include <stdio.h>

int main() {
	char c[2] = { 0 }, n;
	scanf("%d\n", &n);
	while (n--) c[getchar() - 'A']++;
	printf("%s", *c == c[1] ? "Tie" : *c > c[1] ? "A" : "B");
}