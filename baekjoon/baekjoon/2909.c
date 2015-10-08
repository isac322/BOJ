#include <stdio.h>

int a(int a) {
	int temp = 1;

	for (int i = 0; i < a; i++)
		temp *= 10;
	return temp;
}

int main() {
	int C, N,B;

	scanf("%d %d", &C, &N);
	B = C;
	B += a(N) / 2;
	printf("%d",B - (B % a(N)));
}