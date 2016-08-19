#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int arr[3];

	scanf("%d %d %d", arr, arr + 1, arr + 2);
	sort(arr, arr + 3);

	printf("%d", arr[1]);
}