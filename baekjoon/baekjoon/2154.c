#include <stdio.h>
#include <string.h>

int main() {
	char str[488896] = { 0 }, srch[7] = { 0 };
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cnt += sprintf(str + cnt, "%d", i);
	sprintf(srch, "%d", n);
	printf("%d", strstr(str, srch) - str + 1);
}