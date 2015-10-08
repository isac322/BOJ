#include <stdio.h>
#include <string.h>

int main() {
	char str[1001];
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(str);
		putchar(*str);
		putchar(str[strlen(str) - 1]);
		putchar(10);
	}
}