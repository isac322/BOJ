#include <stdio.h>

int main() {
	char tmp[11] = { 0 };
	int arr[] = { 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000 };
	int n, k, t, i = 1;
	scanf("%d %d", &n, &k);
	for (t = 9; k > t; t = arr[i] * (i + 1), i++) k -= t;
	t = (k - 1) / i + arr[i - 1] / 9;
	if (t > n) {
		puts("-1");
		return 0;
	}
	k = (k - 1) % i;
	sprintf(tmp, "%d", t);
	printf("%c", tmp[k]);
}