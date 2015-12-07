#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);
		printf("%d\n", (1u << k) - 1);
	}
}