#include <stdio.h>

int self(int n) {
	int t = n;
	while (n > 0) {
		t += n % 10;
		n /= 10;
	}
	return t;
}

int main() {
	char mat[10001] = { 0 };
	int i = 1, j;
	for (; i <= 10000; i++) {
		if (!mat[i]) {
			for (j = self(i); j < 10001; j = self(j)) mat[j] = 1;
		}
	}
	for (i = 1; i < 10001; i++) if (!mat[i]) printf("%d\n", i);
}