#include <cstdio>
#include <algorithm>

using namespace std;

#define M 10001

int main() {
	int n;
	long long arr[100];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) scanf("%lld", arr + i);

	for (int a = 0; a < M; a++) {
		for (int b = 0; b < M; b++) {
			int i = 1;
			for (; i < n; i++) {
				if ((a*a*arr[i - 1] + a*b + b) % M != arr[i]) break;
			}

			if (i == n) {
				for (int j = 0; j < n; j++) {
					printf("%lld\n", (a*arr[j] + b) % M);
				}
				return 0;
			}
		}
	}
}