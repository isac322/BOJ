#include <cstdio>

using namespace std;

long long arr[100'001];

int main() {
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; arr[i] += arr[i - 1], i++) scanf("%lld", arr + i);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%lld\n", arr[b] - arr[a - 1]);
	}
}