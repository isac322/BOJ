#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int arr[1'000'001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}