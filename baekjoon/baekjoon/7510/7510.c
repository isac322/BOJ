#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	int arr[3];
	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", arr, arr + 1, arr + 2);

		if (arr[0] > arr[1]) {
			int t = arr[1];
			arr[1] = arr[0];
			arr[0] = t;
		}
		if (arr[1] > arr[2]) {
			int t = arr[2];
			arr[2] = arr[1];
			arr[1] = t;
		}

		printf("Scenario #%d:\n%s\n\n", i, arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2] ? "yes" : "no");
	}
}