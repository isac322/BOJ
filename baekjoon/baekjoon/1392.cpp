#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, q, arr[101], t;
	scanf("%d%d", &n, &q);

	scanf("%d", arr);
	arr[0]--;
	for (int i = 1; i < n; i++) {
		scanf("%d", arr + i);
		arr[i] += arr[i - 1];
	}
	arr[n] = arr[n - 1] + 1;

	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		printf("%d\n", lower_bound(arr, arr + n + 1, t) - arr + 1);
	}
}