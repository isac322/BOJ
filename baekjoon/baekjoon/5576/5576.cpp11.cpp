#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int arr[20];
	for (int i = 0; i < 20; i++) scanf("%d", arr + i);
	sort(arr, arr + 10);
	sort(arr + 10, arr + 20);
	printf("%d %d", arr[7] + arr[8] + arr[9], arr[17] + arr[18] + arr[19]);
}