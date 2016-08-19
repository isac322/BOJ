#include <stdio.h>

int main() {
	int t, max = 6;
	long long arr[100] = { 1, 1, 1, 2, 2, 3 };
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (max < n) for (int i = max - 1; i < n; i++) arr[i] = arr[i - 1] + arr[i - 5];
		printf("%lld\n", arr[n - 1]);
	}
}