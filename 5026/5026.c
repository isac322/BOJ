#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int t;
	char in[10], *p;

	scanf("%d\n", &t);
	while (t--) {
		gets(in);
		p = strchr(in, '+');
		if (p) printf("%d\n", atoi(in) + atoi(p + 1));
		else puts("skipped");
	}
}