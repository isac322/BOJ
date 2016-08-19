#include <cstdio>

using namespace std;

int arr[100'001];

int main() {
	int n, m, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; arr[i] += arr[i - 1], i++) scanf("%d", arr + i);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", arr[b] - arr[a - 1]);
	}
}