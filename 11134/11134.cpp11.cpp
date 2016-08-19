#include <cstdio>
#include <cmath>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		printf("%d\n", int(ceil(a / b)));
	}
}