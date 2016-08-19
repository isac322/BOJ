#include <stdio.h>

int main() {
	long long in, sum;
	int t, n;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &in);
			sum += in % n;
		}
		puts(sum % n ? "NO" : "YES");
	}
}