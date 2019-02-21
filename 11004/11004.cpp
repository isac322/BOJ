#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, arr[5000000];
int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	printf("%d", arr[m - 1]);
}