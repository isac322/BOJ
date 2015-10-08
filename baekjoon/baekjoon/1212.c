#include <stdio.h>

int main() {
	char c = 0, n;
	int i = 0, len;
	char s[][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };

	scanf("%c", &c);
	if (c == '0') printf("");
	else if (c == '1') printf("1");
	else if (c == '2') printf("10");
	else if (c == '3') printf("11");
	else printf("%s", s[c - '0']);
	for (i = 0; (n = getchar()) != 10; i++) {
		printf("%s", s[n - '0']);
	}
	if (!i && c == '0') printf("0");
}