#include <stdio.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, k, num, sum = 0;
		scanf("%d%d", &n, &k);

		for (int i = 0; i < n; i++) {
			scanf("%d", &num);
			sum += num / k;
		}

		printf("%d\n", sum);
	}
}