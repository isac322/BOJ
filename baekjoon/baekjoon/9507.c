#include <stdio.h>

int main() {
	int n, i = 4, t;
	scanf("%d", &n);
	long long arr[68] = { 1, 1, 2, 4 };
	for (; i < 68; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
	for (i = 0; i < n; i++) {
		scanf("%d", &t);
		printf("%lld\n", arr[t]);
	}
}