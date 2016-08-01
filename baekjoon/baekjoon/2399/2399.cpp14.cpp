#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10001];

int main() {
	unsigned long long s = 0;
	int n, h;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	h = (n + 1) >> 1;
	for (int i = 0; i < h; i++) s += ((unsigned long long)(arr[n - i - 1] - arr[i]) << 1LLU)*(n - i * 2 - 1);
	printf("%llu", s);
}