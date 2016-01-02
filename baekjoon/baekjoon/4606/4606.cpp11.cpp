#include <cstdio>

int main() {
	int n;
	while ((n = getchar()) != '#') {
		switch (n) {
			case ' ': printf("%%20"); break;
			case '!': printf("%%21"); break;
			case '$': printf("%%24"); break;
			case '%': printf("%%25"); break;
			case '(': printf("%%28"); break;
			case ')': printf("%%29"); break;
			case '*': printf("%%2a"); break;
			default: putchar(n);
		}
	}
}