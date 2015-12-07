#include <stdio.h>
#include <string.h>

main() {
	char s[1000001] = "", t = 0;
	int len, i = 0, j;
	gets(s);
	len = strlen(s);
	if (len % 3) {
		for (i = 0; i < len % 3; t <<= 1, i++) t += s[i] - '0';
		printf("%d", t >> 1);
	}
	for (t = 0; i < len; t = 0, i += 3) {
		for (j = 0; j < 3; j++, t <<= 1) t += s[i + j] - '0';
		printf("%d", t>>1);
	}
}