#include <stdio.h>

int main() {
	int i, n;
	long long arr[90] = { 1, 1 };
	scanf("%d", &n);
	for (i = 2; i < n; i++) arr[i] = arr[i - 1] + arr[i - 2];
	printf("%lld", arr[n - 1]);
}