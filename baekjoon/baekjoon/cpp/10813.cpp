#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[101], n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		swap(arr[a], arr[b]);
	}
	for (int i = 1; i <= n; i++) printf("%d ", arr[i]);
}