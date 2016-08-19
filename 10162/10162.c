#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n % 10) puts("-1");
	else {
		printf("%d ", n / 300);
		n %= 300;
		printf("%d ", n / 60);
		n %= 60;
		printf("%d ", n / 10);
	}
}