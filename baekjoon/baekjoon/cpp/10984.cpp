#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		double sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			int a;
			double b;
			scanf("%d %lf", &a, &b);
			sum2 += a;
			sum1 += b * a;
		}
		printf("%d %.1lf\n", sum2, sum1 / sum2);
	}
}