#include <stdio.h>
#include <string.h>

int main() {
	char str[101], n;
	gets(str);
	for (int i = 0; i < 26; i++) {
		char *p = strchr(str, i + 'a');
		printf("%d ", p ? p - str : -1);
	}
}