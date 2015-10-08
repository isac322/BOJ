#include <stdio.h>
#include <math.h>

int main() {
	double m, b, n;
	while (~scanf("%lf %lf %lf", &n, &b, &m)) printf("%0.lf\n", ceil(log(m / n) / log(1 + b / 100)));
}