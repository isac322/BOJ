#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int t, q = 0;
		scanf("%d", &t);
		for (; q + q*q <= t; q++);
		printf("%d\n", q - 1);
	}
}