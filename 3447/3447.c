#include <stdio.h>
#include <string.h>

int main() {
	char buf[101], len, *p, t, pos = 0;
	while ((t = getchar()) != EOF) {
		if (t != 10) buf[pos++] = t;
		else {
			buf[pos] = 0;
			len = strlen(buf);
			while ((p = strstr(buf, "BUG"))) {
				strcpy(p, p + 3);
				len -= 3;
				buf[len] = 0;
			}
			puts(buf);
			pos = 0;
		}
	}
	if (pos) {
		buf[pos] = 0;
		len = strlen(buf);
		while ((p = strstr(buf, "BUG"))) {
			strcpy(p, p + 3);
			len -= 3;
			buf[len] = 0;
		}
		puts(buf);
	}
}