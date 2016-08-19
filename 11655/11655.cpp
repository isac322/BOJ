#include <cstdio>

int main() {
	char ch;
	while ((ch = getchar()) != -1) {
		if (ch >= 'a' && ch <= 'z') putchar('a' + (ch - 'a' + 13) % 26);
		else if (ch >= 'A' && ch <= 'Z') putchar('A' + (ch - 'A' + 13) % 26);
		else putchar(ch);
	}
}