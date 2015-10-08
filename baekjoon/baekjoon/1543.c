#include <stdio.h>
#include <string.h>

int main() {
	char str[25001], str2[51];
	gets(str);
	gets(str2);

	char *p = str;
	int len = strlen(str2);

	int cnt = 0;
	while ((p = strstr(p, str2)) != NULL) {
		cnt++;
		p += len;
	}

	printf("%d", cnt);
}