#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, t;
	char (*b)[81];

	for (scanf("%d", &n); n; scanf("%d", &n)) {
		char p[1000][81] = { "" };
		getchar();
		for (int i = 0; i < n; i++) {
			gets(p[i]);
		}
		t = (n + 1)/2;
		b = p + t;
		for (int i = 0; i < t; i++) {
			puts(p[i]);
			if (b[i][0]) puts(b[i]);
		}
	}
}