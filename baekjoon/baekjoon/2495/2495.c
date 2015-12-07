#include <stdio.h>

int main() {
	char t, cnt, max, pt, in[9];
	for (int i = 0; i < 3; i++) {
		max = cnt = 1;
		gets(in);
		for (int j = 1; j < 8; j++) {
			if (in[j] == in[j - 1]) cnt++;
			else if (cnt > max) {
				max = cnt;
				cnt = 1;
			} else cnt = 1;
		}
		if (cnt > max) max = cnt;
		printf("%d\n", max);
	}
}