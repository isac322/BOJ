#include <cstdio>
#include <cmath>

using namespace std;

const double a[] = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
const double b[] = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
const double c[] = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};

int main() {
	int n, tmp;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int sum = 0;
		for (int j = 0; j < 7; ++j) {
			scanf("%d", &tmp);
			sum += int(a[j] * pow((j % 3 ? tmp - b[j] : b[j] - tmp), c[j]));
		}
		printf("%d\n", sum);
	}
}