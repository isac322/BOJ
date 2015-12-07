#include <stdio.h>

int gcd(int p, int q){
	if (p%q == 0) return q;
	return gcd(q, p%q);
}

int main() {
	int a[2] = { 0 }, b[2] = { 0 }, tmp;
	int i;
	
	scanf("%d %d %d %d", a, a + 1, b, b + 1);
	b[0] *= a[1];
	a[0] *= b[1];
	b[1] *= a[1];
	b[0] += a[0];
	tmp = gcd(b[0], b[1]);
	printf("%d %d", *b/tmp, b[1]/tmp);
}