#include <stdio.h>
#include <string.h>

int main() {
	char a[1001] = { 0 }, b[1001] = { 0 };
	gets(a);
	gets(b);
	if (strlen(a) >= strlen(b)) puts("go");
	else puts("no");
}