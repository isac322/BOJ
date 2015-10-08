#include <stdio.h>
#include <stdlib.h>

char *check;
short **arr;
short *last;
char *times;
int *nums;
int n, max, tmp;

int calc(int start) {
	int max = 0, num;
	check[start - 1] = 1;
	for (int i = 0; i < last[start - 1]; i++) {
		check[arr[start - 1][i] - 1] = 1;
		num = nums[arr[start - 1][i] - 1] ? nums[arr[start - 1][i] - 1] : calc(arr[start - 1][i]);
		if (num > max) max = num;
	}
	return nums[start - 1] = max + times[start - 1];
}

int main() {
	scanf("%d", &n);
	arr = (short **) calloc(n, sizeof(short *));
	last = (short *) calloc(n, sizeof(short));
	times = (char *) calloc(n, sizeof(char));
	nums = (int *) calloc(n, sizeof(int));
	check = (char *) calloc(n, sizeof(char));
	for (int i = 0; i < n; i++) {
		scanf("%d %d", times + i, last + i);
		arr[i] = (short *) calloc(last[i] + 1, sizeof(short));
		for (int j = 0; j < last[i]; j++) scanf("%d", &arr[i][j]);
	}
	max = calc(n);
	for (int i = n - 1; i >= 0; i--) {
		if (!check[i]) {
			tmp = calc(i + 1);
			if (max < tmp) max = tmp;
		}
	}
	printf("%d", max);
}