#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chng(char *dest) {
	int i = 0;
	char temp;

	for(;i < strlen(dest) / 2; i++) {
		temp = dest[i];
		dest[i] = dest[strlen(dest) - i - 1];
		dest[strlen(dest) - i - 1] = temp;
	}
}

main() {
	char a[5], b[5], c[6];

	scanf("%s %s", a, b);
	chng(a);
	chng(b);
	sprintf(c,"%d",atoi(a)+atoi(b));
	chng(c);
	printf("%d",atoi(c));
}