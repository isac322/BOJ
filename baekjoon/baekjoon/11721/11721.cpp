#include <cstdio>

int main() {
	char c;
	while (true) {
		for (int i = 0; i < 10; i++) {
			if ((c = getchar()) == -1) return 0;
			putchar(c);
		}
		puts("");
	}
}