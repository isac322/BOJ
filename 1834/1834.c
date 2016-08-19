#include <stdio.h>

int main() {
	int N;
	unsigned long long int sum = 0;
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N - 1; i++) {
		sum += N * i + i;
	}
	printf("%llu", sum);
}