#include <stdio.h>

int arr[1000] = { 0 };
int main() {
	int case_n;
	scanf("%d", &case_n);

	while (case_n--) {
		int n, cnt = 0, q;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)	scanf("%d", arr + i);

		for (int i = 0; i < n; i++) {
			int t = i;
			if (arr[t]) cnt++;
			while (arr[t]) {
				q = t;
				t = arr[t] - 1;
				arr[q] = 0;
			}
		}
		printf("%d\n", cnt);
	}
}