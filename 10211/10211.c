#include <stdio.h>
#define max(a, b) a > (b) ? a : (b)

int main() {
	int v[1000];
	int n, t;

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);

		for (int i = 0; i < n; ++i) scanf("%d", v + i);

		int maxSoFar = v[0], curr_max = v[0];

		for (int i = 1; i < n; ++i) {
			curr_max = max(v[i], curr_max + v[i]);
			maxSoFar = max(maxSoFar, curr_max);
		}

		printf("%d\n", maxSoFar);
	}
}