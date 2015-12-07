#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(char *)a - *(char *)b;
}

int main() {
	int num = 0;
	char a[100] = "", b[100] = "";

	scanf("%d\n", &num);
	while (num--) {
		scanf("%s %s", a, b);
		printf("%s & %s are ", a, b);
		qsort(a, strlen(a), sizeof(char), cmp);
		qsort(b, strlen(b), sizeof(char), cmp);
		printf("%sanagrams.\n", strcmp(a, b) ? "NOT " : "");
	}
}