#include <stdio.h>
#include <stdlib.h>

char z[] = { 10, 5, 9, 8, 3, 2, 7, 6, 1, 4 };

int cmp(const void *a, const void *b) {
	char *c = (char *)a, *d = (char *)b;

	if (*c == *d) {
		if (d[1] && c[1]) return z[c[1] - '0'] - z[d[1] - '0'];
		else return c[1] - d[1];
	} else return z[*c - '0'] - z[*d - '0'];
}

int main() {
	int a, b;
	int i;
	char c[101][3] = { 0 };

	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++) {
		sprintf(c[i - a], "%d", i);
	}

	qsort(c, b - a + 1, sizeof(char)* 3, cmp);
	for (i = 0; i <= b - a; i++) {
		if (!(i % 10) && i) puts("");
		printf("%s ", c[i]);
	}
}