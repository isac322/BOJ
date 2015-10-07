#include <cstdio>

using namespace std;

int main() {
	int n, arr[10] = { 0 };
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int t, j = 0;
		scanf("%d", &t);

		while (t) t -= arr[j++] ? 0 : 1;
		while (arr[j]) j++;
		arr[j] = i + 1;
	}

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}