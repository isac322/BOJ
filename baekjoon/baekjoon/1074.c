#include <stdio.h>

int main() {
	int n, r, c, sec, index;
	while (~scanf("%d %d %d", &n, &r, &c)) {
		index = 0;
		do {
			sec = r < (1 << (n - 1)) ? c < (1 << (n - 1)) ? 0 : 1 : c < (1 << (n - 1)) ? 2 : 3;
			index += (1 << ((n << 1) - 2)) * sec;
			switch (sec) {
				case 0: break;
				case 1: c -= (1 << (n - 1)); break;
				case 2: r -= (1 << (n - 1)); break;
				case 3:
					r -= (1 << (n - 1));
					c -= (1 << (n - 1)); break;
			}
		} while (--n);
		printf("%d\n", index);
	}
}