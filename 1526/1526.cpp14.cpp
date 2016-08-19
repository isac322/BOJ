#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[9], tmp[9];

int main() {
	int n;
	scanf("%d", &n);
	int i, j, k = 9, t = 2;
	str[k - 1] = '0';
	for (i = 1; atoi(str + k) <= n; i++) {
		strcpy(tmp, str + k);
		if (i%t == 0) {
			k--;
			t *= 2;
		}
		for (j = 8; j >= k; j--) {
			if (str[j] == '4') {
				str[j] = '7';
				break;
			}
			else str[j] = '4';
		}
	}
	puts(tmp);
}