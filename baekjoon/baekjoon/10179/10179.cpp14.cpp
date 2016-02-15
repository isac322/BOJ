#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		double a;
		scanf("%lf", &a);
		printf("$%.2lf\n", a*0.8);
	}
}