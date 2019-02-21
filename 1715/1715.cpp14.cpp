#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100000], n, sum = 0;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
		arr[i] = -arr[i];
	}
	make_heap(arr, arr + n);
	while (n > 1) {
		pop_heap(arr, arr + n--);
		pop_heap(arr, arr + n);
		sum -= (arr[n - 1] += arr[n]);
		push_heap(arr, arr + n);
	}
	printf("%d", sum);
}