#include <cstdio>

int main() {
	int i, n;
	long long arr[3] = { 1, 1, 1 };
	scanf("%d", &n);
	for (i = 2; i < n; i++) {
		arr[2] = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = arr[2];
	}
	printf("%lld", arr[2]);
}