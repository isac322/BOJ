#include <stdio.h>
#include <string.h>

int main() {
	char in[1001];
	int len, i, j;

	for (gets(in); in[0] - '0' || in[1]; gets(in)) {
		len = strlen(in);
		int bo[1001] = { 0 }, re[1001] = { 0 }, k = 0;

		for (i = 1; i < len; i++) {
			if ((in[i] - '0') - bo[i] != 0) {
				for (j = i; j < len; j += i) {
					bo[j] = bo[j] == 0 ? 1 : 0;
				}
				re[k++] = i;
			}
		}

		for (i = 0; i < k; i++) printf("%d ", re[i]);
		puts("");
	}
}