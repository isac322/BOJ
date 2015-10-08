#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	if (a == 2) {
		if (b == 18) puts("Special");
		else if (b > 18) puts("After");
		else puts("Before");
	}
	else if (a < 2) puts("Before");
	else puts("After");
}