#include <stdio.h>

char b[][7] = { "Adrian", "Bruno", "Goran" };

int main() {
	int n, max;
	int c[3] = { 0 };
	char t, f[9];
	scanf("%d", &n);
	gets(f);
	for (int i = 0; i < n; i++) {
		t = getchar();
		c[0] += t == "ABC"[i % 3];
		c[1] += t == "BABC"[i % 4];
		c[2] += t == "CCAABB"[i % 6];
	}
	max = c[0];
	if (max < c[1]) max = c[1];
	if (max < c[2]) max = c[2];
	printf("%d\n", max);
	for (int i = 0; i < 3; i++) if (c[i] == max) puts(b[i]);
}