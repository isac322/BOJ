#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t, n, maximum = 0, prev, sum = 0;
	scanf("%d%d", &n, &prev);

	for (int i = 1; i < n; i++) {
		scanf("%d", &t);

		if (t > prev) {
			sum += t - prev;
		}
		else {
			maximum = max(maximum, sum);
			sum = 0;
		}
		prev = t;
	}
	printf("%d", max(maximum, sum));
}