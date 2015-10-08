#include <stdio.h>
#include <string.h>

int main() {
	char s1[81] = "", s2[81] = "", c = 0, s3[81] = "", *p1, *p2, ch;
	int pos = 0, len1 = 0, len2 = 0, t, dif, i;
	while ((ch = getchar()) != ' ') {
		if (pos == 0 && ch == '0') continue;
		s1[pos++] = ch - '0';
		len1++;
	}
	pos = 0;
	while ((ch = getchar()) != 10) {
		if (pos == 0 && ch == '0') continue;
		s2[pos++] = ch - '0';
		len2++;
	}
	if (len1 > len2) {
		t = len2;
		dif = len1 - len2;
		p1 = s1;
		p2 = s2;
	} else {
		t = len1;
		dif = len2 - len1;
		p1 = s2;
		p2 = s1;
	}
	for (i = t - 1; i >= 0; i--) {
		int q = c + p1[i + dif] + p2[i];
		switch (q) {
			case 0:
				c = 0;
				s3[i + dif] = 0;
				break;
			case 1:
				c = 0;
				s3[i + dif] = 1;
				break;
			case 2:
				c = 1;
				s3[i + dif] = 0;
				break;
			case 3:
				c = 1;
				s3[i + dif] = 1;
		}
	}
	for (i = dif - 1; i >= 0; i--) {
		switch (p1[i] + c) {
			case 0:
				c = 0;
				s3[i] = 0;
				break;
			case 1:
				c = 0;
				s3[i] = 1;
				break;
			case 2:
				c = 1;
				s3[i] = 0;
				break;
		}
	}
	if (c) putchar('1');
	for (i = 0; i < t + dif; i++) printf("%c", s3[i] ? '1' : '0');
	if (t + dif == 0) putchar('0');
}