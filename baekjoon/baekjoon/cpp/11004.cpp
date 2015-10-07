#include <cstdio>
#include <algorithm>

using namespace std;

int n, k;
int arr[5000000];

int findK(int start, int end) {
	int index = start;

	int pivotValue = arr[start];
	swap(arr[start], arr[end]);
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivotValue) {
			swap(arr[index], arr[i]);
			index++;
		}
	}
	swap(arr[end], arr[index]);

	if (index == k) return arr[index];
	else if (index < k) return findK(index + 1, end);
	else return findK(start, index - 1);
}

int main() {
	scanf("%d %d", &n, &k);
	k--;
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	printf("%d", findK(0, n - 1));
}