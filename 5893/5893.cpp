#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(void) {
	char num1[1010], num2[1010], s[1010], result[1010] = { 0 };
	int i, len;

	scanf("%s", s);
	sprintf(num1, "00000%s", s);
	sprintf(num2, "0%s0000", s);

	len = strlen(num1);
	for (i = len - 1; i > 0; i--) {
		result[i] += num1[i] - '0' + num2[i] - '0';

		if (result[i] >= 2) {
			result[i] -= 2; result[i - 1] += 1;
		}
	}
	for (i = result[0] == 0 ? 1 : 0; i < len; i++) {
		printf("%d", result[i]);
	}
}