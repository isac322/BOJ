#include <stdio.h>
#include <string.h>

int main() {
	char str[16], t;
	char c = 0;
	gets(str);
	int len = strlen(str);
	printf("..");
	for (int i = 1; i < len; i++) printf("%c...", i % 3 == 0 ? '*' : '#');
	printf("%c..\n.", len % 3 == 0 ? '*' : '#');
	for (int i = 1; i <= len; i++) {
		t = i % 3 == 0 ? '*' : '#';
		printf("%c.%c.", t, t);
	}
	puts("");
	for (int i = 1; i <= len; i++) {
		if (i % 3 == 0) {
			c = 1;
		} else if (c == 1 && (i - 1) % 3 != 0) c = 0;
		printf("%c.%c.", c ? '*' : '#', str[i - 1]);
	}
	printf("%c\n.", c && (len - 1) % 3 != 0 ? '*' : '#');
	for (int i = 1; i <= len; i++) {
		t = i % 3 == 0 ? '*' : '#';
		printf("%c.%c.", t, t);
	}
	puts("");
	printf("..");
	for (int i = 1; i < len; i++) printf("%c...", i % 3 == 0 ? '*' : '#');
	printf("%c..", len % 3 == 0 ? '*' : '#');
}