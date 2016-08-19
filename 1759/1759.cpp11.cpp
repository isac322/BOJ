#include <cstdio>
#include <algorithm>

using namespace std;

char str[16], l, c, tmp[16], len, cnt[26];

void p(char i) {
	if (len == l) {
		int t = cnt[0] + cnt[4] + cnt[8] + cnt[14] + cnt[20];
		tmp[l] = 0;
		if (t >= 1 && l - t >= 2) puts(tmp);
	}
	else if (i < c) {
		tmp[len++] = str[i];
		cnt[str[i] - 'a']++;
		p(i + 1);
		cnt[str[i] - 'a']--;
		len--;
		p(i + 1);
	}
}

int main() {
	scanf("%hhd %hhd\n", &l, &c);
	for (char i = 0; i < c; i++, getchar()) str[i] = getchar();
	sort(str, str + c);
	p(0);
}