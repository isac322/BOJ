#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);

	int w = 0;
	for (int i = 0; i < n; i++) w = max(w, arr[i] * (n - i));
	printf("%d", w);
}