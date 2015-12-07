#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *) a - *(int *) b; }

int main() {
	int i, j, n, arr[20000] = { 0 }, index = 0, min = 0x7fffffff, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), cmp);
	for (i = 0; i < n; i++) {
		for (sum = j = 0; j < i; j++) sum += arr[j];
		sum = arr[i] * i - sum;
		for (j = i + 1; j < n; j++) sum += arr[j];
		sum -= arr[i] * (n - i - 1);
		if (min > sum) {
			min = sum;
			index = i;
		}
	}
	printf("%d", arr[index]);
}