#include <stdio.h>
#include <string.h>

int main() {
	char str[10001], *p;
	int j = 0, i = 0;
	gets(str);

	for (p = strstr(str, "JOI"); p; j++) p = strstr(p + 3, "JOI");
	for (p = strstr(str, "IOI"); p; i++) p = strstr(p + 2, "IOI");

	printf("%d\n%d", j, i);
}