#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, h;
	scanf("%d %d", &n, &h);

	int arr1[100000], arr2[100000];

	n >>= 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", arr1 + i);
		scanf("%d", arr2 + i);
	}

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);

	int min = 987654321, count = 0;
	for (int i = 1; i <= h; i++) {
		int tmp = n - (lower_bound(arr1, arr1 + n, i) - arr1) + n - (lower_bound(arr2, arr2 + n, h - i + 1) - arr2);
		if (min == tmp) count++;
		else if (min > tmp) {
			min = tmp;
			count = 1;
		}
	}

	printf("%d %d\n", min, count);
}