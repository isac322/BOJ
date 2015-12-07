#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[8];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);

	int ret = 0;
	sort(arr, arr + n);
	do {
		int sum = 0;
		for (int i = 1; i < n; i++) sum += abs(arr[i - 1] - arr[i]);
		ret = max(ret, sum);
	} while (next_permutation(arr, arr + n));

	printf("%d", ret);
}