#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10000];
int main() {
	int t, n, m, i;
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		sort(arr, arr + n);

		m = arr[1] - arr[0], i = 2;
		for (; i < n; i += 2) m = max(m, arr[i] - arr[i - 2]);
		m = max(m, arr[n - 1] - arr[i - 2]);
		i = n & 1 ? n - 2 : n - 1;
		m = max(m, arr[n - 1] - arr[i]);
		for (; i > 1; i -= 2) m = max(m, arr[i] - arr[i - 2]);

		printf("%d\n", m);
	}
}