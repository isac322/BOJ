#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	char in[106] = { 0 }, temp[106] = { 0 };
	char *p = NULL;
	int i = 0, len = 0, psum = 0;

	gets(in);
	len = strlen(in);
	if (len % 3) {
		for (; i < 3 - len % 3; i++) {
			strcpy(temp, in);
			strcpy(in + 1, temp);
			in[0] = '0';
		}
	}
	len = strlen(in);

	for (i = len / 3; i > 0; psum = 0, i--) {
		p = in + len - i * 3;
		if (*p == '1') psum += 4;
		if (*(p + 1) == '1') psum += 2;
		if (*(p + 2) == '1') psum += 1;
		printf("%d", psum);
	}
}