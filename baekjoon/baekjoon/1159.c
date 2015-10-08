#include <stdio.h>

int main() {
	int n, i, a[26] = { 0 };
	char tmp[31];
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(tmp);
		a[tmp[0] - 'a']++;
	}
	for (n = 0, i = 0; i < 26; i++) {
		if (a[i] > 4) {
			printf("%c", i + 'a');
			n++;
		}
	}
	if (!n) puts("PREDAJA");
}