#include <cstdio>

int main() {
	int n, b, g, c;
	scanf("%d\n", &n);
	while (n--) {
		b = g = 0;
		while ((c = getchar()) != 10) {
			switch (c) {
				case 'g':
				case 'G': g++; break;
				case 'b':
				case 'B': b++;
			}
			putchar(c);
		}
		printf(" is %s\n", b == g ? "NEUTRAL" : b > g ? "A BADDY" : "GOOD");
	}
}