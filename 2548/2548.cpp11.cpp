#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, arr[20000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	printf("%d", arr[--n >> 1]);
}