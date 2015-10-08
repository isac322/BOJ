#include <stdio.h>

int main() {
	double max = 0.0, n[4], a, b, c, d;
	int t;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	n[0] = a / c + b / d;
	n[1] = c / d + a / b;
	n[2] = d / b + c / a;
	n[3] = b / a + d / c;
	for (int i = 0; i < 4; i++) {
		if (max < n[i]) {
			max = n[i];
			t = i;
		}
	}
	printf("%d", t);
}