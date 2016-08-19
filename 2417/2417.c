#include <stdio.h>
#include <math.h>

int main() {
	long long i;
	scanf("%lld", &i);
	printf("%lld", (long long)ceill(sqrtl(i)));
}