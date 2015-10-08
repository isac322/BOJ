#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char t, o;
	int len1 = 0, len2 = 0;
	while ((t = getchar()) != '\n') len1++;
	o = getchar();
	getchar();
	while ((t = getchar()) != '\n') len2++;

	if (o == '+') {
		if (len1 == len2) {
			putchar('2');
			for (int i = 1; i < len1; i++) {
				putchar('0');
			}
		}
		else {
			putchar('1');
			if (len1 < len2) swap(len1, len2);

			for (int i = 1; i < len1; i++) {
				putchar(len1 - i == len2 ? '1' : '0');
			}
		}
	}
	else {
		putchar('1');
		for (int i = 0; i < len1 + len2 - 2; i++) putchar('0');
	}
}