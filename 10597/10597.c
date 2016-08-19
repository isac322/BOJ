#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void*b) { return *(char *) a - *(char *) b; }

char str[92];
char jump[50] = { 0 }, p = 0;

int f(int n) {
	char num[4], *p, *pos = str;
	int len = sprintf(num, "%d", n), i;
	if (n == 1) {
		p = strstr(str, num);
		if (p) {
			jump[0] = p - str + 1;
			return 1;
		} else return 0;
	}

	while ((p = strstr(pos, num))) {
		for (i = 0; i < len; i++) p[i] = ' ';
		if (f(n - 1)) {
			for (i = 0; i < len; i++) p[i] = num[i];
			jump[n - 1] = p - str + len;
			return 1;
		} else {
			for (i = 0; i < len; i++) p[i] = num[i];
			pos = p + 1;
		}
	}
	return 0;
}

int main() {
	int t, i = 0, t2;
	gets(str);
	t2 = t = strlen(str);
	if (t > 9) t = (t - 9) / 2 + 9;
	if (f(t)) {
		qsort(jump, t, sizeof(char), cmp);
		for (i = 0; i < t2; i++) {
			if (i == jump[p]) {
				printf(" ");
				p++;
			}
			printf("%c", str[i]);
		}
	}
}