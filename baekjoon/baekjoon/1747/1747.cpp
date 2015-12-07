#include <stdio.h>
#include <algorithm>

using namespace std;

bool prime[1003001] = { true, true, false };

bool check(int n) {
	char str[8] = "";
	int len = sprintf(str, "%d", n);

	for (int i = 0; i < (len >> 1); i++) {
		if (str[i] != str[len - i - 1]) return false;
	}
	return true;
}

int main() {
	for (int i = 2; i <= 1002; i++) {
		if (!prime[i]) {
			for (int j = i << 1; j <= 1003001; j += i) {
				prime[j] = true;
			}
		}
	}

	int n;
	scanf("%d", &n);
	for (int i = n; i <= 1003001; i++) {
		if (!prime[i] && check(i)) {
			printf("%d", i);
			return 0;
		}
	}
}