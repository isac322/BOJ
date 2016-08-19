#include <stdio.h>

int main() {
	char a[3], tmp[100];
	int max, n, nsum = 0;
	double b, sum = 0;

	scanf("%d", &max);
	while (max--) {
		scanf("%s %d %s", tmp, &n, a);

		if (*a < 69) b = 69 - *a;
		else b = 0;
		
		if (a[1] == '+') b += 0.3;
		else if (a[1] == '-') b -= 0.3;
		
		sum += n*b;
		nsum += n;
	}
	printf("%.2lf", sum / nsum + 0.001);
}