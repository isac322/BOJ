#include <cstdio>

char a[26], ch, cnt;
int main() {
	while (~scanf("%c", &ch)) a[ch - 65]++;
	for (int i = 0; i < 26; i++) if (a[i] & 1) cnt++, ch = i + 65;
	if (cnt > 1) puts("I'm Sorry Hansoo");
	else {
		for (int i = 0; i < 26; a[i++] >>= 1) for (int j = 0; j < a[i] / 2; j++) putchar(i + 65);
		if (cnt) putchar(ch);
		for (int i = 25; i >= 0; i--) while (a[i]--) putchar(i + 65);
	}
}