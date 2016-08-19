#include <stdio.h>
#include <math.h>

int main() {
	int a, b, n, arr[5] = { 0 };
	scanf("%d%d%d", &a, &b, &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	int cnt = 0, min = abs(a - b) , index = -1, tmp;
	for (int i = 0; i < n; i++) {
		if (abs(arr[i] - b) < min) {
			index = i;
			min = abs(arr[i] - b);
			tmp = arr[i];
		}
	}
	if (index == -1) {
		printf("%d", min);
	} else if (tmp == a) {
		printf("%d", min);
	} else printf("%d", min + 1);
}