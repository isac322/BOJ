#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(char *) b - *(char *) a; }

char num[100001];
int main() {
	int sum = 0, i = 0;
	gets(num);
	for (; num[i]; i++) sum += num[i] - '0';
	qsort(num, i, sizeof(char), cmp);
	if (num[i - 1] == '0' && sum % 3 == 0) puts(num);
	else puts("-1");
}