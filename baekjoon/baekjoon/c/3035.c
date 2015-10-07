#include <stdio.h>

int main() {
	int r, c, zr, zc, len;
	char t, str[250];
	scanf("%d %d %d %d\n", &r, &c, &zr, &zc);
	for (int i = 0; i < r; i++) {
		len = 0;
		for (int j = 0; j < c; j++) {
			t = getchar();
			for (int l = 0; l < zc; l++) str[len++] = t;
		}
		str[len] = 0;
		for (int j = 0; j < zr; j++) puts(str);
		getchar();
	}
}