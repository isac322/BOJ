#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[10000] = { 0 }, tot = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		tot += arr[i];
	}

	sort(arr, arr + n);

	int limit;
	scanf("%d", &limit);

	if (limit >= tot) {
		printf("%d\n", arr[n - 1]);
	} else {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			int sub = limit - sum;

			int tmp = sub / (n - i);
			if (tmp <= arr[i]) {
				printf("%d\n", tmp);
				return 0;
			}

			sum += arr[i];
		}
	}
}