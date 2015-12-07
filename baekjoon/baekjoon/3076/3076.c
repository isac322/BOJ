#include <stdio.h>

int main() {
	int r, a, c, b;
	scanf("%d%d%d%d", &r, &c, &a, &b);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < c; k++) for (int l = 0; l < b; l++) putchar((i + k) % 2 == 0 ? 'X' : '.');
			puts("");
		}
	}
}