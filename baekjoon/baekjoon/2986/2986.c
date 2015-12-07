#include <stdio.h>
#include <math.h>

int main() {
	int n, i = 2, tmp;
	scanf("%d", &n);
	tmp = sqrt(n);
	for (; i <= tmp; i++) {
		if (!(n%i)) break;
	}
	printf("%d", i == tmp + 1 ? n - 1 : n - n / i);
}