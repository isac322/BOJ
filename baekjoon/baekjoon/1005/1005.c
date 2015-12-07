#include <stdio.h>

short arr[1000][1000] = { 0 };
int last[1000] = { 0 };
short time[1000] = { 0 };
int nums[1000] = { 0 };
int n, k;

int calc(int start) {
	int max = 0, num;
	for (int i = 0; i < last[start - 1]; i++) {
		num = nums[arr[start - 1][i] - 1] ? nums[arr[start - 1][i] - 1] : calc(arr[start - 1][i]);
		if (num > max) max = num;
	}
	return nums[start - 1] = max + time[start - 1];
}

int main() {
	int t, s, e, l;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; i++) {
			nums[i] = 0;
			last[i] = 0;
			scanf("%d", time + i);
		}

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &s, &e);
			arr[e - 1][last[e - 1]++] = s;
		}

		scanf("%d", &l);
		printf("%d\n", calc(l));
	}
}