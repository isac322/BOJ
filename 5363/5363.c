#include <stdio.h>

int main() {
	char a[99], b[99], c[99];
	int n;
	int i = 0;
	scanf("%d", &n);
	for (; i < n; i++) {
		scanf("%s %s ", b, c);
		gets(a);
		printf("%s %s %s\n", a, b, c);
	}
}