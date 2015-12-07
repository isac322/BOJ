#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main() {
	int num, i, min, index[2] = { 0, 1 }, half, index_max, tmp, j;
	int arr[100000] = { 0 };

	scanf("%d", &num);
	for (i = 0; i < num; i++) scanf("%d", arr + i);

	qsort(arr, num, sizeof(int), cmp);

	min = arr[0] + arr[1];
	if (arr[num - 1] + arr[num - 2] < min) {
		min = arr[num - 1] + arr[num - 2];
		index[0] = num - 2;
		index[1] = num - 1;
	}

	if (arr[0] > 0 && arr[num - 1] > 0) {
		printf("%d %d", arr[0], arr[1]);
		return 0;
	} else if (arr[0] < 0 && arr[num - 1] < 0) {
		printf("%d %d", arr[num - 2], arr[num - 1]);
		return 0;
	} else {
		for (half = 0; arr[half] < 0; half++);
		index_max = num - 1;

		for (i = 0; i < half; i++) {
			while (arr[index_max] + arr[i] > 0) index_max--;

			for (j = -1; j < 2; j++) {
				if (j + index_max > num) continue;
				tmp = arr[index_max + j] + arr[i];
				if (abs(tmp) < abs(min)) {
					min = tmp;
					index[0] = i;
					index[1] = index_max + j;
				}
			}
		}
		printf("%d %d", arr[index[0]], arr[index[1]]);
	}
}