#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100] = { 0 };
int fib[45] = { 0, 1 };

int main() {
	int case_n;
	scanf("%d", &case_n);

	for (int i = 2; i < 45; i++) fib[i] = fib[i - 1] + fib[i - 2];

	while (case_n--) {
		int n;
		scanf("%d", &n);

		int tmp = n, cnt = 0;
		do {
			int *p = upper_bound(fib, fib + 45, tmp) - 1;

			tmp -= *p;
			arr[cnt] = *p;
			cnt++;
		} while (tmp > 0);
		sort(arr, arr + cnt);
		for (int i = 0; i < cnt; i++) {
			printf("%d ", arr[i]);
		}
		puts("");
	}
}