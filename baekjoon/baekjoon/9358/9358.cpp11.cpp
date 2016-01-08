#include <cstdio>

int main() {
	int t, n, arr[100];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", arr + i);
		while (n > 2) {
			for (int i = 0; i < (n + 1) / 2; i++) arr[i] += arr[n - i - 1];
			n = ++n >> 1;
		}
		printf("Case #%d: %s\n", i, arr[0] > arr[1] ? "Alice" : "Bob");
	}
}