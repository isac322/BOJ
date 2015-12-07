#include <stdio.h>
#define PI 3.14159265358979323846264338327950288419716939937510

int main() {
	double r;
	scanf("%lf", &r);
	printf("%lf\n%lf", r*r*PI, r*r * 2);
}