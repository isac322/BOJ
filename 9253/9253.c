#include <stdio.h>
#include <string.h>

int main() {
	char str1[200001], str2[2000001], str3[200001];
	gets(str1);
	gets(str2);
	gets(str3);
	puts(strstr(str1, str3) && strstr(str2, str3) ? "YES" : "NO");
}