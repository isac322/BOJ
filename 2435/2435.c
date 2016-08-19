#include <stdio.h>

int main() {
	char tmp[100] = { 0 };
	int n, k, sum = 0, max;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", tmp + i);
		sum += tmp[i];
	}
	max = sum;
	for (int i = k; i < n; i++) {
		scanf("%d", tmp + i);
		sum += tmp[i] - tmp[i - k];
		if (max < sum) max = sum;
	}
	printf("%d", max);
}