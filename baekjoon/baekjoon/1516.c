#include <stdio.h>

char check[500];
short arr[500][500] = { 0 };
short last[500] = { 0 };
short times[500] = { 0 };
int nums[500] = { 0 };
int n, max, tmp, i, j;

int calc(int start) {
	int max = 0, num;
	check[start - 1] = 1;
	for (int i = 0; i < last[start - 1]; i++) {
		num = nums[arr[start - 1][i] - 1] ? nums[arr[start - 1][i] - 1] : calc(arr[start - 1][i]);
		if (num > max) max = num;
	}
	return nums[start - 1] = max + times[start - 1];
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", times + i);
		for (j = 0; scanf("%d", &arr[i][j]) && arr[i][j] != -1; j++);
		last[i] = j;
	}
	calc(n);
	for (int i = n - 1; i >= 0; i--) if (!check[i]) calc(i + 1);
	for (i = 0; i < n; i++) { printf("%d\n", nums[i]); }
}