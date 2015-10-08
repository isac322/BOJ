#include <stdio.h>

int main() {
	int r, l, i, j;
	char m, *p, e[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", n[27] = { 0 }, t[27], o[27], a[27];

	scanf("%d\n%d\n", &l, &r);
	gets(n);

	p = e;
	for (i = 0; i < 26; i++) t[i] = i;
	for (i = 0; i < r; i++) {
		for (j = 0; j < l - 1; j++) {
			switch (getchar()) {
			case '-': m = p[j];
				p[j] = p[j + 1];
				p[j + 1] = m;
				break;
			case '?': p = t;
			}
		}
		getchar();
	}

	for (i = 0; i < l; i++) a[t[i]] = n[i];
	for (i = 0; i < l - 1; i++) {
		if (e[i] == a[i]) o[i] = '*';
		else if (e[i] == a[i + 1] && e[i + 1] == a[i]) {
			o[i] = '-';
			o[i + 1] = '*';
			i++;
		} else {
			for (j = 0; j < l - 1; j++) putchar('x');
			return 0;
		}
	}
	o[l - 1] = 0;
	puts(o);
}