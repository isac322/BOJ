#include <stdio.h>
#include <string.h>

int main() {
	char buf[128];
	gets(buf);
	for (int i = 0; buf[i]; i++) {
		putchar(buf[i]);
		if (strchr("aeiou", buf[i])) i += 2;
	}
}