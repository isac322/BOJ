#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[21];
	for (int i = 0; i < 20; i++) arr[i] = i + 1;
	for (int i = 0; i < 10; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		reverse(arr + a - 1, arr + b);
	}
	for (int i = 0; i < 20; i++) printf("%d ", arr[i]);
}