#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	int arr[3];
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", arr, arr + 1, arr + 2);
		sort(arr, arr + 3);
		printf("Scenario #%d:\n%s\n\n", i, arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2] ? "yes" : "no");
	}
}