#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, arr[101] = {0};
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) arr[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		reverse(arr + a, arr + b + 1);
	}
	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
}