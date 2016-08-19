#include <cstdio>

using namespace std;

int main() {
	int n, arr[1000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", arr + i);
	for (int i = 0; i < n; i++) {
		int num = arr[i];
		bool plus = false;
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
			if (plus) num += arr[j];
			else num -= arr[j];
			plus = !plus;
		}
		printf("%d\n", num >> 1);
	}
}