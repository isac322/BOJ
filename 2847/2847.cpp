#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[100], m, s = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	m = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] >= m) s += arr[i] - m + 1;
		m = min(m - 1, arr[i]);
	}
	printf("%d", s);
}