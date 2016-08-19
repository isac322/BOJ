#include <cstdio>

int main() {
	int index = 0, ch, s = 0;

	while (true) {
		index++;
		switch (ch = getchar()) {
			case '#':
				return 0;
			case '\n':
				printf("%d\n", s);
				s = index = 0;
				break;
			case ' ':
				break;
			default:
				s += (ch - 64) * index;
				break;
		}
	}
}