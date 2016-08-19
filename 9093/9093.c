#include <stdio.h>

int main() {
	int t, pos = 20;
	char ch, arr[22];

	scanf("%d\n", &t);
	while (t) {
		switch ((ch = getchar())) {
			case 10: t--;
			case 32: printf("%s%c", arr + pos + 1, ch); pos = 20; break;
			default: arr[pos--] = ch;
		}
	}
}