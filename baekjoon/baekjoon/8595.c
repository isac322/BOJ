#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
	int num, t = 0;
	long long sum = 0;
	int i, cnt = 0;
	char ch;

	scanf("%d\n", &num);

	for (i = 0; i < num; i++) {
		ch = getchar();

		if (isdigit(ch)) {
			if (cnt < 6) {
				t *= 10;
				t += ch - '0';
				cnt++;
			} else if (cnt == 6) {
				sum += t;
				t = cnt = 0;
				while (isdigit((ch = getchar()))) i--;
			}
		} else if (cnt > 0) {
			sum += t;
			t = cnt = 0;
		}
	}
	sum += t;


	printf("%lld\n", sum);
}