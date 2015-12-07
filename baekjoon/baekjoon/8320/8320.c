#include <stdio.h>

int main() {
	int n, j, i = 2, sum;

	scanf("%d", &n);
	sum = n;
	for (; i*i <= n; i++) {
		for (j = i; j*i <= n; j++) sum++;
	}
	printf("%d\n", sum);
}