#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%d %d", (int)(a / sqrt(b*b + c*c) * b), (int)(a / sqrt(b*b + c*c) * c));
}