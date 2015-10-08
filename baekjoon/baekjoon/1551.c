#include <stdio.h>

int n, k, arr[20] = { 0 };
int main() {
	scanf("%d %d\n%d", &n, &k, arr);
	for (int i = 1; i < n; i++) scanf(",%d", arr + i);
	while (k--) {
		n--;
		for (int i = 0; i < n; i++) arr[i] = arr[i + 1] - arr[i];
	}
	printf("%d", arr[0]);
	for (int i = 1; i < n; i++) printf(",%d", arr[i]);
}