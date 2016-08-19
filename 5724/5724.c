#include<stdio.h>

int main(){
	long V[101];
	long n;
	for (V[0] = 0, n = 1; n <= 100; n++)
		V[n] = V[n - 1] + n*n;
	while (scanf("%ld", &n) && n)
		printf("%ld\n", V[n]);
}