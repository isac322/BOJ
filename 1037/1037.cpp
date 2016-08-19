#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[50] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	sort(arr, arr + n);
	printf("%d", arr[0] * arr[n - 1]);
}