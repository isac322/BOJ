#include <stdio.h>
using namespace std;

bool *check;
short **arr;
short *last;
short *times;
int *nums;
int n, max, tmp;

int calc(int start) {
	int max = 0, num;
	check[start - 1] = true;
	for (int i = 0; i < last[start - 1]; i++) {
		check[arr[start - 1][i] - 1] = true;
		num = nums[arr[start - 1][i] - 1] ? nums[arr[start - 1][i] - 1] : calc(arr[start - 1][i]);
		if (num > max) max = num;
	}
	return nums[start - 1] = max + times[start - 1];
}

int main() {
	scanf("%d", &n);
	arr = new short *[n]();
	last = new short[n]();
	times = new short[n]();
	nums = new int[n]();
	check = new bool[n]();
	for (int i = 0; i < n; i++) {
		scanf("%d %d", times + i, last + i);
		arr[i] = new short[last[i] + 1]();
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