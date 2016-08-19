#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int h = n >> 1;
	int v = n - h + 1;

	printf("%d", ++h*v);
}